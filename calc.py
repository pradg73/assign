#!/usr/bin/python
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

    # operator -> calculation , priority
    oper = {
        '*' : [lambda x,y : Val(x*y), 2],
        '+' : [lambda x,y : Val(x+y),1],
        '-' : [lambda x,y : Val(x-y),1],
        '/' : [lambda x,y : Val(x/y),3],
    }

    def __init__(self, _op):
        self.op = _op

    # precedence
    def isGreater(self, rhs):
        return Op.oper[self.op][1] > Op.oper[rhs.op][1]

    def eval(self, rhs, lhs):
        print "eval op ",self.op
        return Op.oper[self.op][0](rhs.eval(), lhs.eval())

class Expr(object):

    @staticmethod
    def eval(exprs):
        print "eval ", exprs
        lastLowestOp = None
        lastLowestOpLocation = -1

        if len(exprs) == 1:
            token = exprs[0]
            assert(Val.is_number(token))
            return Val(token)

        for i,token in enumerate(exprs):
            print "token ",token
            if token in Op.oper.keys():
                op = Op(token)

                if lastLowestOp is None:
                    lastLowestOp = op
                    lastLowestOpLocation = i
                elif lastLowestOp.isGreater(op): # op < lastLowestOp
                    lastLowestOp = op
                    lastLowestOpLocation = i

        assert(lastLowestOpLocation != -1)
        lhs = Expr.eval(exprs[:lastLowestOpLocation])
        rhs = Expr.eval(exprs[lastLowestOpLocation+1:])

        return lastLowestOp.eval(lhs, rhs)

if __name__ == "__main__":
    exprs = sys.argv[1];

    print Expr.eval(exprs).eval()
