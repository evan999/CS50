import cs50


pyramid_height = input("Enter the height of the pyramid: ")

def get_pyramid_height():

    while True:
        try:
         pyramid_height = input("Enter the height of the pyramid: ")
        except ValueError:
            continue
        else:
            return pyramid_height
            break
#for pyramid_level in range(pyramid_height):

