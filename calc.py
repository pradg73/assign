#!/opt/bb/bin/python
import sys

class Val(object):
    val = None

    def __init__(self, _val):
        self.val = int(_val)

    def eval(self):
        return self.val

    @staticmethod
    def is_number(s):
        try:
            int(s)
            return True
        except ValueError:
            pass

class Op(object):
    op = None

    oper = {
        '*' : lambda x,y : x*y,
    }

    def __init__(self, _op):
        self.op = _op

    def eval(self, rhs, lhs):
        print "eval op ",self.op
        return self.oper[self.op](rhs.eval(), lhs.eval())

class Expr(object):
    list = []
    def parse(self,exprs):
        for token in exprs:
            print "token ",token
            if token in ['*','+','-']:
                self.list.extend([Op(token)])
            elif Val.is_number(token):
                self.list.extend([Val(token)])

    def eval(self):
        result = 0
        operands = []
        operators = []

        for t in self.list:
            print "t: ",type(t)
            if type(t) is Val:
                operands.extend([t])
            elif type(t) is Op:
                operators.extend([t])

        while len(operators) != 0:
            rhs = operands.pop()
            lhs = operands.pop()
            e = operators.pop().eval(rhs,lhs)
            operands.extend([Val(e)])

        assert(len(operators) == 0)
        assert(len(operands) == 1)
        return operands.pop().val

if __name__ == "__main__":
    exprs = sys.argv[1];
    print exprs
    expr = Expr()
    expr.parse(exprs)
    print expr.eval()
