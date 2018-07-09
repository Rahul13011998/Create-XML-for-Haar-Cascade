import os

def createDescriptor():
    directory = 'neg'
    for img in os.listdir(directory):
        line = directory + '/' + img + '\n'
        with open('bg.txt', 'a') as file:
            file.write(line)

if __name__=='__main__':
    createDescriptor()