import os
from datetime import datetime, timedelta

def generate_readme(date):
    readme_content = f"""<h1>{date}</h1>

<h3>What did I learn today</h3>

<ul>
    <li>...</li>
    <li>...</li>
</ul>

<h3>Things I'm grateful for </h3>

<ul>
    <li>...</li>
    <li>...</li>
</ul>

<h3>Links And Resources </h3>

<ul>
    <li>...</li>
    <li>...</li>
</ul>
        """
    return readme_content

def create_month_template(month, year,dir):
    month_name = datetime(year, month, 1).strftime("%B")
    month_folder = f"{month_name}-{year}"
    days_in_month = [(datetime(year, month, day).strftime("%d-%B-%Y")) for day in range(1, 32) if datetime(year, month, day, 0, 0).month == month]

    # Create base folder
    base_folder = os.path.join(dir, month_folder)
    os.makedirs(base_folder, exist_ok=True)
    os.chdir(base_folder)

    # Create subfolders for each day and generate readme
    for day in days_in_month:
        day_folder = os.path.join(base_folder, day)
        if not os.path.exists(day_folder):
            os.makedirs(day_folder)
            readme_content = generate_readme(day)
            with open(os.path.join(day_folder, "readme.md"), "w") as f:
                f.write(readme_content)
            print(f"Created folder: {day}")
        else:
            print(f"Folder already exists: {day}")

    print(f"Month template for {month_name} {year} created successfully.")

if __name__ == "__main__":
    year = 2024
    month = 5  # Example for May 2024
    dir = './EveryDayCoding'
    create_month_template(month, year,dir)
