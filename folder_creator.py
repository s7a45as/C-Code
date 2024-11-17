import os
from datetime import datetime
import string

def create_contest_folders():
    # 获取用户输入的比赛名称
    contest_name = input("请输入比赛名称（例如：南宁周赛）：")
    
    # 获取当前日期并组合比赛名称作为根文件夹名
    current_date = datetime.now().strftime(f"%Y\\%m\\%d{contest_name}")
    
    # 创建根文件夹
    os.makedirs(current_date, exist_ok=True)
    
    # 创建 AfterContest 和 BeforeContest 文件夹
    contest_types = ['AfterContest', 'BeforeContest']
    
    for contest_type in contest_types:
        contest_path = os.path.join(current_date, contest_type)
        os.makedirs(contest_path, exist_ok=True)
        
        # 在每个文件夹下创建 A-M 的子文件夹
        for letter in string.ascii_uppercase[:13]:  # A到M共13个字母
            problem_folder = os.path.join(contest_path, letter)
            os.makedirs(problem_folder, exist_ok=True)
    
    print(f"文件夹创建完成！")

if __name__ == "__main__":
    try:
        create_contest_folders()
        input("按回车键退出...")
    except Exception as e:
        print(f"创建文件夹时发生错误: {str(e)}")
        input("按回车键退出...") 