import time as t
class Arbol:
    def christmasTree():
        print("\n"*4)
        print("   F E L I Z  N A V I D A D  A  T O D O S")
        t.sleep(1)
        print("\n")
        for i in range(5):
            t.sleep(1)
            for j in range(5):
                k = 10 - i 
                k = k - j
                print(""*i,end="")
                # At every layer we increase the numbers of Symbols, for it we add i to j
                j = j + i
                # mind the space that is used to balance the pattern
                print("  "*k,"@*. "*j, end="\n",sep=".*")
        print(" "*2,"-"*35)
        print("   ===================================")
        print(" "*2,"-"*35)
        for i in range(4):
            print(" "*17,"HHHH")
        print("\n"*4)

if __name__=="__main__":
    a = Arbol
    a.christmasTree()
