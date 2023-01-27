import os
from PIL import Image, ImageFont, ImageDraw

def count_files(path, extension):
    count = 0
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(extension):
                count += 1
    return count

def replace_first_line(filepath, new_line):
    with open(filepath, 'r') as f:
        lines = f.readlines()
    lines[0] = new_line
    with open(filepath, 'w') as f:
        f.writelines(lines)

def text_to_image(text, font_path, font_size, image_path):
    font = ImageFont.truetype(font_path, font_size)
    size = font.getbbox(text)
    image = Image.new('RGBA', (size[2], size[3]), (255, 255, 255, 0))
    draw = ImageDraw.Draw(image)
    draw.text((0,0), text, font=font)
    image.save(image_path)


path = "F:\\repos\\Problems"
extension = ".cpp"

count = count_files(path, extension)

# generate image with text
text = f"Number of .cpp files: {count}"
font_path = "arial.ttf"
font_size = 12
image_path = os.path.join(path, "count.png")
text_to_image(text, font_path, font_size, image_path)
