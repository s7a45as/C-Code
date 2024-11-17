import os
import string
from datetime import datetime

def is_problem_solved(contest_path, letter):
    """
    检查题目是否已完成，满足以下任一条件即视为已完成：
    1. Contest文件夹中存在包含'ok'的cpp文件
    2. AfterContest文件夹中存在包含'ok'的cpp文件
    """
    def check_cpp_files(folder_path):
        if not os.path.exists(folder_path):
            return False
            
        # 获取文件夹中所有的cpp文件
        cpp_files = [f for f in os.listdir(folder_path) if f.endswith('.cpp')]
        
        # 检查是否有包含'ok'的cpp文件
        for cpp_file in cpp_files:
            if 'ok' in cpp_file.lower():
                return True
        return False
    
    # 检查Contest文件夹
    contest_problem_path = os.path.join(os.path.dirname(contest_path), 'Contest', letter)
    if check_cpp_files(contest_problem_path):
        return True
        
    # 检查AfterContest文件夹
    after_contest_problem_path = os.path.join(contest_path, letter)
    return check_cpp_files(after_contest_problem_path)

def generate_contest_record():
    try:
        # 使用相对路径，从当前文件所在目录开始
        current_dir = os.path.dirname(os.path.abspath(__file__))
        base_path = os.path.join(current_dir, "2024")
        record = []
        
        # 检查基础路径是否存在
        if not os.path.exists(base_path):
            print(f"错误: 未找到目录 {base_path}")
            return False
            
        # 遍历月份
        for month in sorted(os.listdir(base_path)):
            month_path = os.path.join(base_path, month)
            if not os.path.isdir(month_path):
                continue
                
            # 遍历日期
            for day in sorted(os.listdir(month_path)):
                day_path = os.path.join(month_path, day)
                if not os.path.isdir(day_path):
                    continue
                    
                # 检查 AfterContest 文件夹
                after_contest_path = os.path.join(day_path, "AfterContest")
                if not os.path.exists(after_contest_path):
                    continue
                    
                # 统计该场比赛的题目情况
                solved_problems = []
                total_problems = []
                
                # 获取所有可能的题目文件夹
                problem_folders = set()
                contest_path = os.path.join(day_path, "Contest")
                if os.path.exists(contest_path):
                    problem_folders.update(
                        f for f in os.listdir(contest_path) 
                        if os.path.isdir(os.path.join(contest_path, f)) 
                        and f in string.ascii_uppercase
                    )
                if os.path.exists(after_contest_path):
                    problem_folders.update(
                        f for f in os.listdir(after_contest_path) 
                        if os.path.isdir(os.path.join(after_contest_path, f)) 
                        and f in string.ascii_uppercase
                    )
                
                # 检查每个题目的状态
                for letter in sorted(problem_folders):
                    total_problems.append(letter)
                    if is_problem_solved(after_contest_path, letter):
                        solved_problems.append(letter)
                
                if total_problems:  # 只要有题目文件夹就记录
                    contest_name = day[2:]  # 去掉日期，保留比赛名称
                    record.append({
                        'date': f"2024-{month}-{day[:2]}",
                        'contest': contest_name,
                        'solved': solved_problems,
                        'total': total_problems
                    })
        
        # 生成Markdown格式的记录
        output_path = os.path.join(current_dir, "contest_record.md")
        with open(output_path, "w", encoding='utf-8') as f:
            f.write("# 补题记录\n\n")
            f.write("| 日期 | 比赛 | 已完成题目 | 待补题目 | 完成率 |\n")
            f.write("|------|------|------------|-----------|--------|\n")
            
            for entry in record:
                solved = ", ".join(entry['solved']) if entry['solved'] else "无"
                unsolved = ", ".join([l for l in entry['total'] if l not in entry['solved']]) if entry['total'] != entry['solved'] else "全部完成"
                completion_rate = f"{len(entry['solved'])}/{len(entry['total'])} ({len(entry['solved'])*100/len(entry['total']):.1f}%)"
                
                f.write(f"| {entry['date']} | {entry['contest']} | {solved} | {unsolved} | {completion_rate} |\n")
        
        print(f"补题记录已生成完成！保存在: {output_path}")
        return True
        
    except Exception as e:
        print(f"生成记录时发生错误: {str(e)}")
        print(f"错误类型: {type(e).__name__}")
        print(f"错误位置: {os.path.basename(__file__)}")
        return False

if __name__ == "__main__":
    try:
        success = generate_contest_record()
        if success:
            print("程序执行成功！")
        else:
            print("程序执行失败！")
    except Exception as e:
        print(f"程序执行出错: {str(e)}")
    finally:
        input("按回车键退出...") 