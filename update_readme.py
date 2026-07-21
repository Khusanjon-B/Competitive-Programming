import os
import re

ROOT_DIR = "."
README_PATH = "README.md"
TARGET_DIRS = ["CodeForces", "CSES", "USACO", "HackerRank"]

HEADER_REGEX = {
    "problem": re.compile(r"//\s*Problem:\s*(.+)"),
    "link": re.compile(r"//\s*Link:\s*(.+)"),
    "topics": re.compile(r"//\s*Topics:\s*(.+)"),
    "time": re.compile(r"//\s*Time Complexity:\s*(.+)"),
    "space": re.compile(r"//\s*Space Complexity:\s*(.+)"),
}

def parse_cpp_file(filepath):
    """Extracts header comments from a C++ file."""
    info = {
        "problem": os.path.basename(os.path.dirname(filepath)),
        "link": "-",
        "topics": "General",
        "time": "-",
        "space": "-",
        "path": filepath.replace("\\", "/")
    }
    
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read(2048) # Read first 2KB for headers
            
            for key, pattern in HEADER_REGEX.items():
                match = pattern.search(content)
                if match:
                    info[key] = match.group(1).strip()
    except Exception as e:
        print(f"Error reading {filepath}: {e}")
        
    return info

def generate_readme():
    entries = {category: [] for category in TARGET_DIRS}
    
    # Scan target directories
    for category in TARGET_DIRS:
        cat_path = os.path.join(ROOT_DIR, category)
        if not os.path.exists(cat_path):
            continue
            
        for root, _, files in os.walk(cat_path):
            for file in files:
                if file.endswith(".cpp"):
                    full_path = os.path.join(root, file)
                    file_info = parse_cpp_file(full_path)
                    entries[category].append(file_info)

    total_solved = sum(len(v) for v in entries.values())

    # Generate Markdown Content
    md_content = f"""# Competitive Programming & DSA Portfolio

Welcome to my competitive programming repository! This repository automatically tracks and categorizes my solutions from **Codeforces**, **CSES**, **USACO**, and **HackerRank**.

---

## Profiles & Stats
* **Total Solved in Repo:** {total_solved}
* **Codeforces:** [khusanjonb](https://codeforces.com/profile/khusanjonb)
* **CSES:** [Khusanjon](https://cses.fi/user/384721)
* **HackerRank:** [kbobokhojaev](https://www.hackerrank.com/profile/kbobokhojaev)

---

## Solved Problems Index
"""

    for category, problems in entries.items():
        if not problems:
            continue
            
        md_content += f"\n### {category} ({len(problems)})\n"
        md_content += "| Problem Name | Topics | Time | Space | Solution |\n"
        md_content += "| :--- | :--- | :--- | :--- | :--- |\n"
        
        for p in sorted(problems, key=lambda x: x["problem"]):
            link_str = f"[{p['problem']}]({p['link']})" if p['link'] != "-" else p['problem']
            file_link = f"[`{os.path.basename(p['path'])}`](./{p['path']})"
            md_content += f"| {link_str} | {p['topics']} | {p['time']} | {p['space']} | {file_link} |\n"

    md_content += "\n---\n*Updated automatically via `update_readme.py`*\n"

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(md_content)

    print(f"Successfully generated {README_PATH} with {total_solved} problems!")

if __name__ == "__main__":
    generate_readme()