import os
import re
import urllib.parse

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
    clean_path = os.path.normpath(filepath).replace("\\", "/")
    if clean_path.startswith("./"):
        clean_path = clean_path[2:]

    folder_name = os.path.basename(os.path.dirname(filepath))

    info = {
        "problem": folder_name,
        "link": "-",
        "topics": "General",
        "time": "-",
        "space": "-",
        "path": clean_path
    }
    
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read(2048) # Read header section
            
            for key, pattern in HEADER_REGEX.items():
                match = pattern.search(content)
                if match:
                    info[key] = match.group(1).strip()
    except Exception as e:
        print(f"Error reading {filepath}: {e}")
        
    # Auto-generate Codeforces link if missing (e.g. extracts '118' and 'A' from '118A StringTask')
    if info["link"] == "-" and "CodeForces" in clean_path:
        cf_match = re.match(r"^(\d+)([A-Z]\d*)", folder_name)
        if cf_match:
            contest_id, index = cf_match.group(1), cf_match.group(2)
            info["link"] = f"https://codeforces.com/problemset/problem/{contest_id}/{index}"

    return info

def generate_readme():
    entries = {category: [] for category in TARGET_DIRS}
    
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

    md_content = f"""# Competitive Programming & DSA Portfolio

Welcome to my competitive programming repository! This repository automatically tracks and categorizes my solutions from **Codeforces**, **CSES**, **USACO**, and **HackerRank**.

---

## Profiles & Stats
* **Total Solved in Repo:** {total_solved}
* **Codeforces:** [khusanjonb](https://codeforces.com/profile/khusanjonb)
* **CSES:** [Khusanjon](https://cses.fi/user/384721)
* **HackerRank:** [kbobokhojaev](https://www.hackerrank.com/profile/kbobokhojaev)
* **Kattis:** [kb](https://open.kattis.com/users/khusanjon-bobokhojaev)

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
            
            # URL encode spaces for local file markdown links
            encoded_path = urllib.parse.quote(p['path'])
            file_link = f"[`{os.path.basename(p['path'])}`](./{encoded_path})"
            
            md_content += f"| {link_str} | {p['topics']} | {p['time']} | {p['space']} | {file_link} |\n"

    md_content += "\n---\n*Updated automatically via `update_readme.py`*\n"

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(md_content)

    print(f"Successfully generated {README_PATH} with {total_solved} problems!")

if __name__ == "__main__":
    generate_readme()