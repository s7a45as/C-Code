import os

def rename_file():
    # 获取当前文件夹中的所有文件
    files = [f for f in os.listdir('.') if os.path.isfile(f) and f != 'rename.py' and f != 'README.md']
    
    if not files:
        print("当前文件夹没有找到需要重命名的文件")
        return
        
    # 读取README.md获取题目要点
    try:
        with open('README.md', 'r', encoding='utf-8') as f:
            content = f.read()
            # 查找题目描述部分
            start = content.find('## 题目描述')
            if start != -1:
                # 获取题目描述的第一行作为关键词
                desc_lines = content[start:].split('\n')
                if len(desc_lines) > 2:  # 确保有描述内容
                    keyword = desc_lines[2].strip()[:30]  # 取前30个字符
                else:
                    keyword = "未命名"
            else:
                keyword = "未命名"
    except:
        keyword = "未命名"
    
    # 为每个文件重命名
    for old_name in files:
        # 获取文件扩展名
        name, ext = os.path.splitext(old_name)
        # 新文件名格式：原名_关键词_ok.扩展名
        new_name = f"{name}_{keyword}_ok{ext}"
        
        try:
            os.rename(old_name, new_name)
            print(f"已将 {old_name} 重命名为 {new_name}")
        except Exception as e:
            print(f"重命名 {old_name} 时发生错误: {str(e)}")

if __name__ == "__main__":
    rename_file()
