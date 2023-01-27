import os

def count_cpp_files(directory):
    count = 0
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.cpp'):
                count += 1
    return count

def main():
    directory = 'Problems'
    count = count_cpp_files(directory)

    with open('output.md', 'w') as f:
        f.write(f'Number of .cpp files: {count}')

if __name__ == '__main__':
    main()
