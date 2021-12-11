#Copyright 2021 Zhaowen Zhou zzwzhou@bu.edu
#Copyright 2021 Shuyi Fan shuyifan@bu.edu
class Polynomial():
    
    def __init__(self, coefficients = 0, c: int = 1 ):
        if coefficients == 0:
            self.coefficients = []
        
        else:
            self.coefficients = coefficients
            self.negcoefficients = []
            if len(self.coefficients) == 1:
                num = self.coefficients[0]
                if num >= 0:
                    for i in range (num):
                        self.coefficients.append(0)
                    self.coefficients[0] = c
                
                else:
                    self.negcoefficients.append(abs(num))
                    self.negcoefficients.append(c)
                
    def __setitem__(self, index, value):
        size = len(self.coefficients)
        if index > size:
            for i in range(index - size + 1):
                self.coefficients.insert(0, 0)
            self.coefficients[0] = value
                
        if index < size:
            self.coefficients[size - index - 1] = value
            
        if index == size:
            self.coefficients[0] = value
            
        sparse = self.coefficients
        return Polynomial(sparse)
    
    def __add__(self, value):
        c1 = self.coefficients
        c2 = value.coefficients
        
        if len(c1) > len(c2):
            diff = len(c1) - len(c2)
            for i in range(diff):
                c2.insert(0, 0)
        else:
            diff = len(c2) - len(c1)
            for i in range(diff):
                c1.insert(0, 0)
                
        sum_coefficients = []
        for i in range(len(c1)):
            sum_coefficients.append(c1[i] + c2[i])            
        return Polynomial(sum_coefficients)
    
    def __sub__(self, value):
        c1 = self.coefficients
        c2 = value.coefficients
        if len(c1) > len(c2):
            diff = len(c1) - len(c2)
            for i in range(diff):
                c2.insert(0, 0)
        else:
            diff = len(c2) - len(c1)
            for i in range(diff):
                c1.insert(0, 0)                
        sub_coefficients = []
        
        for i in range(len(c1)):
            sub_coefficients.append(c1[i] - c2[i])
            
        return Polynomial(sub_coefficients)
    
    def deriv(self):
        der_coff = []
        exp = len(self.coefficients) - 1
        for i in range(len(self.coefficients)):
            der_coff.append(self.coefficients[i] * exp)
            exp -= 1
        
        return Polynomial(der_coff)
    
    def __eq__(self, value):
        return self.coefficients == value.coefficients
    
    def __mul__(self, other):
        m = len(self.coefficients)
        n = len(other.coefficients)
        prod = [0] * (m + n - 1)
        
        for i in range(m):
            for j in range(n):
                prod[i + j] += self.coefficients[i] * other.coefficients[j]
        return Polynomial(prod)
    
    def eval(self, x):
        result = 0
        if not self.negcoefficients:
            for index, coff in enumerate(reversed(self.coefficients)):
                result = result + coff*x**index
            return result
        else:
            result = self.negcoefficients[1]*(1/x**self.negcoefficients[0])
            return result