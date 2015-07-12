import time

def consumer():
    r = ''
    while True:
        n = yield r
        if not n:
            return 
        print ("[consumer] consuming %s..." % n)
        time.sleep(1)
        r = "200 OK"

def produce(c):
    c.next()
    n = 0
    while (n < 5):
        n = n+1
        print ("[Producer] producing %s..." % n)
        r = c.send(n)
        print ("[Producer] consumer return %s..." %n)
    c.close()

if __name__ == "__main__":
    c = consumer()
    produce(c)
