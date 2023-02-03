def replace_first_line(path, new_line):
    with open(path, "r") as file:
        lines = file.readlines()
    lines[0] = new_line + "\n"
    with open(path, "w") as file:
        file.writelines(lines)