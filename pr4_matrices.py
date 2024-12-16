def transpose(matrix1,mat1rows,mat1columns,result):
    for j in range(0,mat1rows):
        for i in range(0,mat1columns):
            result[j][i]=matrix1[i][j]

        print("Transpose of matrix1: ")
        for i in range(0,mat1rows):
            for j in  range(0,mat1columns):
                print(result[i][j],end="")
            print()

def addition(matrix1,matrix2,mat1rows,mat2columns,result):
    for i in range(0,mat1rows):
        for j in range(0,mat1columns):
            result[i][j]=matrix1[i][j]+matrix2[i][j]
    print("Addition of Two Matrix: ")
    for i in range(0,mat1rows):
        for j in range(0,mat1columns):
            print(result[i][j],end="")
        print()

def substraction(matrix1,matrix2,mat1rows,mat2columns,result):
    for i in range(0,mat1rows):
        for j in range(0,mat1columns):
            result[i][j]= matrix1[i][j]- matrix2[i][j]
    print("Substraction of Two Matrix: ")
    for i in range(0,mat1rows):
        for j in range(0,mat1columns):
            print(result[i][j],end="")
        print()


def multiplication(matrix1,matrix2):
    temp=[0,0],[0,0]
    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                temp[i][j]+=matrix1[i][k]*matrix2[k][j]
                
        print("Multiplication of two Matrix: ")
        for result in temp:
            print(result)
            
if __name__ == "__main__":

    #matrix1
    print("\nData Input - Matrix1")
    mat1rows=int(input("Enter number of rows:"))
    mat1columns=(int(input("Enter number of columns:")))
    matrix1=[]

    for i in range(0,mat1rows):
        a=[]
        for j in range(0,mat1columns):
            a.append(int(input()))
        matrix1.append(a)       

    print("\nMatrix1:")

    for i in range(0,mat1rows):
        for j in range(0,mat1columns):
            print(matrix1[i][j],end="")
        print()

    #matrix2
    print("\nData Input - Matrix2")
    mat2rows=int(input("Enter number of rows:"))
    mat2columns=(int(input("Enter number of columns:")))
    matrix2=[]

    for i in range(0,mat2rows):
        a=[]
        for j in range(0,mat2columns):
            a.append(int(input()))
        matrix2.append(a)       

    print("\nMatrix2:")

    for i in range(0,mat2rows):
        for j in range(0,mat2columns):
            print(matrix2[i][j],end="")
        print()

    result=[[0,0],[0,0]]
    print("")
    print("MENU")
    print("1.Addition")
    print("2.Multiplication")
    print("3.Substraction")
    print("4.Transpose")
    print("Press 0 to Exit")

    while(True):
        cases=int(input("Enter your input here :"))
        print("\n")
        match cases:
        
            case 0:
                print("Exit")
                break
            case 1:
                addition(matrix1,matrix2,mat1rows,mat2columns,result)
            case 2:
                multiplication(matrix1,matrix2)
            case 3:
                substraction(matrix1,matrix2,mat1rows,mat2columns,result)
            case 4:
                transpose(matrix1,matrix2,mat1rows,mat1columns,result)
            case _:
                print("Invalid Input......")
