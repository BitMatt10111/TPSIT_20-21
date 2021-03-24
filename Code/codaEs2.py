#Author: Matteo Lamberti
#Target: Reverse a queue using a stack

def push(stack,element):
    stack.append(element)

def pop(stack):
    return stack.pop()

def dequeue(queue):
    return queue.pop(0)

def enqueue(queue,element):
    queue.append(element)

def main():
    queue=[]
    stack=[]
    while True:
        element=int(input())
        enqueue(queue,element)
        ans=input("Insert n if you want to shut down and s to continue: ")
        if ans=="n" or ans=="N":
            break

    for _ in range(len(queue)):
        push(stack,dequeue(queue))

    for _ in range(len(stack)):
        enqueue(queue,pop(stack))

    for _ in range(len(queue)):
        print(dequeue(queue))

if __name__ == "__main__":
    main()