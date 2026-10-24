import torch
import copy
from ultralytics import YOLO

# 1. 加载权重
model = YOLO("./yolov5nu.pt")

# 2. 深度拷贝底层的 PyTorch 模型
pytorch_model = copy.deepcopy(model.model)

# 3. 找到最后的检测头(Detect Head)，将原本的 80 类强行修改为 1 类（人）
if hasattr(pytorch_model, 'model') and hasattr(pytorch_model.model[-1], 'nc'):
    detect_head = pytorch_model.model[-1]
    
    # 记录原本的类别数（80类）
    old_nc = detect_head.nc
    
    # 强制修改检测头的类别数为 1
    detect_head.nc = 1 
    
    # YOLOv5u 的 cv3 是一个 nn.ModuleList，里面包含 3 个解耦的分类卷积分支
    # 它的通道排列非常简单：由于是 Anchor-free，最后一层输出通道数直接等于老类别数 80。
    # 我们只需要切片提取第 0 类（人）的权重
    for conv_block in detect_head.cv3:
        # conv_block 通常是一个 Sequential 或自定义 Conv，其最后一个子层是真正的 nn.Conv2d
        # 在 Ultralytics 的 Conv 封装中，真正的卷积层在 .conv 属性里
        target_layer = conv_block[-1] if isinstance(conv_block, torch.nn.Sequential) else conv_block.conv
        
        old_w = target_layer.weight.data  # 形状一般为 [80, 输入通道, 1, 1]
        old_b = target_layer.bias.data    # 形状一般为 [80]
        
        # 核心切片：强行只提取第 0 类（人）对应的权重和偏置
        target_layer.weight.data = old_w[0:1, ...] # 裁剪后形状变为 [1, 输入通道, 1, 1]
        target_layer.bias.data = old_b[0:1]         # 裁剪后形状变为 [1]
        
        # 同时修改当前卷积层的 out_channels 属性为 1
        target_layer.out_channels = 1

    print(f"成功将模型最后一层从 {old_nc} 类物理裁剪为 1 类（人）")

# 4. 把裁剪后的底层模型塞回 YOLO 框架中
model.model = pytorch_model

# 5. 执行导出 (配合 NCNN，开启 simplify=True 提前合并碎算子)
model.export(format="onnx", imgsz=640, simplify=True)
print("🎉 物理精简单人类别 ONNX 导出成功。")

