import os
from datetime import datetime
import string

def create_readme_content(letter):
    return f"""# 题目 {letter}

## 题目描述
[在此填写题目描述]

## 解题思路
"""

def create_rename_script_content():
    return '''import os

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
                desc_lines = content[start:].split('\\n')
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
'''

def create_contest_folders():
    # 获取用户输入的比赛名称
    contest_name = input("请输入比赛名称（例如：南宁周赛）：")
    
    # 获取用户输入的题目数量
    while True:
        try:
            problem_count = int(input("请输入题目数量（1-13）："))
            if 1 <= problem_count <= 13:
                break
            else:
                print("题目数量必须在1到13之间，请重新输入")
        except ValueError:
            print("请输入有效的数字")
    
    # 获取当前日期并组合比赛名称作为根文件夹名
    current_date = datetime.now().strftime(f"%Y\\%m\\%d{contest_name}")
    
    # 创建根文件夹
    os.makedirs(current_date, exist_ok=True)
    
    # 创建 AfterContest 和 Contest 文件夹
    contest_types = ['AfterContest', 'Contest']
    
    for contest_type in contest_types:
        contest_path = os.path.join(current_date, contest_type)
        os.makedirs(contest_path, exist_ok=True)
        
        # 在每个文件夹下创建指定数量的题目文件夹
        for i in range(problem_count):
            letter = string.ascii_uppercase[i]  # 从A开始的字母
            problem_folder = os.path.join(contest_path, letter)
            os.makedirs(problem_folder, exist_ok=True)
            
            # 创建 README.md 文件
            with open(os.path.join(problem_folder, "README.md"), "w", encoding='utf-8') as f:
                f.write(create_readme_content(letter))
            
            # 创建 rename.py 文件
            with open(os.path.join(problem_folder, "rename.py"), "w", encoding='utf-8') as f:
                f.write(create_rename_script_content())
    
    print(f"已创建{problem_count}道题目的文件夹")
    
    # 更新补题记录
    try:
        from contest_record_generator import generate_contest_record
        if generate_contest_record():
            print("补题记录已成功更新！")
        else:
            print("补题记录更新失败！")
    except ImportError as e:
        print(f"未找到contest_record_generator.py，跳过更新补题记录: {str(e)}")
    except Exception as e:
        print(f"更新补题记录时发生错误: {str(e)}")
    
    print(f"文件夹和文件创建完成！")

if __name__ == "__main__":
    try:
        create_contest_folders()
        input("按回车键退出...")
    except Exception as e:
        print(f"创建文件夹时发生错误: {str(e)}")
        input("按回车键退出...") 