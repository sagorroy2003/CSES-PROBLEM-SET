import requests
from bs4 import BeautifulSoup
import re

def get_solved_problems(username):
    """Fetch solved problems from CSES for given username"""
    url = f"https://cses.fi/problemset/user/{username}/"
    try:
        response = requests.get(url, timeout=10)
        response.raise_for_status()
        
        soup = BeautifulSoup(response.text, 'html.parser')
        
        # Find all solved problems (they have 'full' class)
        solved_problems = soup.find_all('a', class_='full')
        return len(solved_problems)
        
    except Exception as e:
        print(f"Error fetching data: {e}")
        return 0

def update_readme(total_solved):
    """Update the README.md file with new solved count"""
    try:
        with open('README.md', 'r') as file:
            content = file.read()
        
        # Update total solved count
        new_content = re.sub(
            r'\| Total \| \*\*400\*\* \| \*\*(\d+)\*\* \|',
            f'| Total | **400** | **{total_solved}** |',
            content
        )
        
        with open('README.md', 'w') as file:
            file.write(new_content)
            
        print(f"Updated README with {total_solved} solved problems")
        
    except Exception as e:
        print(f"Error updating README: {e}")

if __name__ == "__main__":
    USERNAME = "sagor_roy"  # Your CSES username
    solved_count = get_solved_problems(USERNAME)
    update_readme(solved_count)