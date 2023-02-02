import os
from PIL import Image, ImageFont, ImageDraw
import datetime

def count_files(path, extension):
    count = 0
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(extension):
                count += 1
    return count

def replace_first_line(path, new_line):
    with open(path, "r") as file:
        lines = file.readlines()
    lines[0] = new_line + "\n"
    with open(path, "w") as file:
        file.writelines(lines)




def text_to_image(text, font_path, font_size, image_path):
    font = ImageFont.truetype(font_path, font_size*10)
    size = font.getbbox(text)
    width,height = (800,400)
    image = Image.new('RGBA', (width, height), (255, 255, 0, 255))
    draw = ImageDraw.Draw(image)
    x = (width - 600) / 2
    y = (height - 180) / 2
    draw.text((x, y), text, font=font, fill='blue')
    image.save(image_path)





path = "F:\\repos\\Problems\\"
extension = ".cpp"

count = count_files(path, extension)

# get current time
now = datetime.datetime.now()

# generate image with text
text = f"Solved: {count}"
font_path = "arial.ttf"
font_size = 12
image_path = os.path.join("F:\\repos\\Problems\\tools\\", "{}_{}_{}.png".format(now.hour, now.minute, now.second))
text_to_image(text, font_path, font_size, image_path)

new_line = f"![count.png](tools/{now.hour}_{now.minute}_{now.second}.png?v=2)"
replace_first_line("F:\\repos\\Problems\\README.md", new_line)
