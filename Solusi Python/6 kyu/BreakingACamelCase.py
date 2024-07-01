"""

Complete the solution so that the function will break up camel casing, using a space between words.
Example
    "camelCasing"  =>  "camel Casing"
    "identifier"   =>  "identifier"
    ""             =>  ""

"""

def solution(s):
    if (s == ''): #cek string jika kosong
        return ''
    
    bucket = [] #bucket berfungdi tuntuk menampung seluruh Kata yang terdapat pada string
    Word = "" #untuk update setiap kata jika ketemu huruf kapital
    for i in range(0, len(s), 1):
        if(s[i].isupper()):
            if(i == 0):
                Word += s[i]
                bucket.append(Word)
                Word = ""
            else: 
                bucket.append(Word)
                Word = ""
                Word += s[i]
        elif(i == len(s) -1 ):
            Word += s[i]
            bucket.append(Word)
            
        else:
            Word += s[i]
        
        result = ""
    for i in range(0, len(bucket), 1):
        result += bucket[i] + " "
        
    result = result.rstrip()
    return result

input_string = input('Enter CamelCase string: ')
print(solution(input_string))