#Author: Matteo Lamberti
#Target: Load a queue of integer

def dequeue(queue):
    return queue.pop(0)

def enqueue(queue,element):
    queue.append(element)

def main():
    queue=[]
    while True:
        element=int(input())
        enqueue(queue,element)
        ans=input("Insert n if you want to shut down and s to continue: ")
        if ans=="n" or ans=="N":
            break
    
    for _ in range(len(queue)):
        print(dequeue(queue))

if __name__ == "__main__":
    main()