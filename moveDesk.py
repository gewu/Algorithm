import math

class MoveDesk(object):
    def process(self, r, x, y, x1, y1):
        l = math.sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))
        if l < r:
            return 1
        else: 
            return int((l-r)/2r)+1

if __name__ == "__main__":
    md = MoveDesk()
    print md.process(2,0,0,4,4)

