import os
import re
import math

README_FILE = "README.md"

# ✅ Updated CSES categories (correct totals = 400)
CATEGORIES = {
    "Introductory-Problems": 24,
    "Sorting-and-Searching": 35,
    "Dynamic-Programming": 23,
    "Graph-Algorithms": 36,
    "Range-Queries": 25,
    "Tree-Algorithms": 16,
    "Mathematics": 37,
    "String-Algorithms": 21,
    "Geometry": 16,
    "Advanced-Techniques": 25,
    "Sliding-Window-Problems": 11,
    "Interactive-Problems": 6,
    "Bitwise-Operations": 11,
    "Construction-Problems": 8,
    "Advanced-Graph-Problems": 28,
    "Counting-Problems": 18,
    "Additional-Problems-I": 30,
    "Additional-Problems-II": 30,
}

TOTAL_PROBLEMS = sum(CATEGORIES.values())  # 400

BAR_LENGTH = 10  # Length of mini progress bars

def count_solved():
    category_progress = {cat: 0 for cat in CATEGORIES}
    solved_list = []

    for category in CATEGORIES:
        if os.path.exists(category):
            for file in os.listdir(category):
                if file.endswith(".cpp"):
                    category_progress[category] += 1
                    solved_list.append(f"{category}/{os.path.splitext(file)[0]}")

    total_solved = sum(category_progress.values())
    return total_solved, category_progress, solved_list

def create_progress_bar(solved, total, length=BAR_LENGTH):
    if total == 0:
        return "░" * length
    proportion = solved / total
    filled = math.ceil(proportion * length)
    return "█" * filled + "░" * (length - filled)

def update_readme(total_solved, category_progress, solved_list):
    with open(README_FILE, "r", encoding="utf-8") as f:
        content = f.read()

    # Update overall progress badge
    content = re.sub(
        r"Progress-\d+%2F\d+",
        f"Progress-{total_solved}%2F{TOTAL_PROBLEMS}",
        content,
    )

    # Update category-wise table
    table_pattern = re.compile(r"\| Category.*?\|\s*\*\*Total\*\*.*?\|", re.S)
    new_table = "| Category                  | Total | Solved | Progress |\n"
    new_table += "|----------------------------|------:|-------:|---------|\n"

    for category, total in CATEGORIES.items():
        solved = category_progress[category]
        status_bar = create_progress_bar(solved, total)
        new_table += f"| {category.replace('-', ' '):26} | {total:<4} | {solved}/{total:<4} | {status_bar} |\n"

    new_table += f"| **Total**                  | {TOTAL_PROBLEMS:<4} | {total_solved}/{TOTAL_PROBLEMS:<4} | {'█'*BAR_LENGTH} |\n"

    content = table_pattern.sub(new_table + "|", content)

    # Update solved problems list
    if "### ✅ Solved Problems" in content:
        solved_section = "\n".join([f"- {p}" for p in sorted(solved_list)])
        content = re.sub(
            r"(### ✅ Solved Problems\n)(.*?)(\n---)",
            r"\1" + solved_section + r"\3",
            content,
            flags=re.S,
        )

    with open(README_FILE, "w", encoding="utf-8") as f:
        f.write(content)

if __name__ == "__main__":
    total_solved, category_progress, solved_list = count_solved()
    update_readme(total_solved, category_progress, solved_list)
    print(f"Updated README with {total_solved}/{TOTAL_PROBLEMS} problems solved.")
