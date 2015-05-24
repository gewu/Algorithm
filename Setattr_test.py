class AccessCounter(object):

    def __init__(self, val):
        super(AccessCounter, self).__setattr__('counter', 0)
        super(AccessCounter, self).__setattr__('value', val)

    def __setattr__(self, name, value):
        if name == 'value':
            super(AccessCounter, self).__setattr__('counter', self.counter + 1)
        super(AccessCounter, self).__setattr__(name, value)

    def __delattr__(self, name):
        if name == "value":
            super(AccessCounter, self).__setattr__('counter', self.counter+1)
        super(AccessCounter, self).__delattr__(name)

if __name__ == "__main__":

    ac = AccessCounter(3)
    ac.value = 4
    print ac.counter
