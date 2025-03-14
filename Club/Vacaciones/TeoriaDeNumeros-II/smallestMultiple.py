from math import *
from sys import *

while 1:
  numeros = stdin.readline()[:-1] #-1 para quitar el salto de linea
  if not numeros:
    break
  numeros = list(map(int, numeros.split())) #convierte la cadena de numeros a una lista de enteros
  res=1
  for i in range(len(numeros)):
    res=(res*numeros[i]//gcd(res,numeros[i]))
  print(res)