import PySimpleGUI as sg
import math
from PySimpleGUI.PySimpleGUI import WINDOW_CLOSED, Window


def suma():
	layout = [
			[sg.Text("Primer numero: ")],
			[sg.Input(key='-INPUT1-')],
			[sg.Text("Segundo numero: ")],
			[sg.Input(key='-INPUT2-')],	
			[sg.T(key='Resultado')],
			[sg.Button('Aceptar'), sg.Button('Salir')]
		]

	window = sg.Window('Suma', layout, modal=True)

	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break

		a=int(values['-INPUT1-'])
		b=int(values['-INPUT2-'])

		window['Resultado'].update("La suma de {0} + {1} es {2}".format(values['-INPUT1-'], values['-INPUT2-'], sumar(a, b)))
	window.close()

def sumar(a, b):
	return (a + b)



def areaRectangulo():
	layout = [
			[sg.T("Base del rectangulo: ")], [sg.I(key='Base')],
			[sg.T("Altura del rectangulo: ")], [sg.I(key='Altura')],
			[sg.T(key='Resultado')],
			[sg.B('Aceptar'), sg.B('Salir')]
		]
	window = sg.Window('Area Rectangulo', layout, modal=True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break

		a = int(values['Altura'])
		b = int(values['Base'])
		area = (b * a)
		window['Resultado'].update('El area del rectangulo es: {}'.format(area))
		# print("Area es igual a: {}".format(area))
	window.close()


def multiplicacion():
	layout = [
				[sg.T("Multiplicacion de numeros: ")],[sg.Input(key="Numeros")],
				[sg.B('Aceptar'), sg.B('Salir')]
			]
	window = sg.Window("Multiplicacion", layout, modal=True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		Sep = values['Numeros'].split('*')
		clean = [num.strip(' ') for num in Sep]
		Total = [int(i) for i in clean]
		Fin = 1
		for x in Total:
			Fin *= x
		print(Fin)
	window.close()

# def mul(n):
# 	total = 1
# 	for i in range(0, len(n)):
# 		total *= n[i]
# 	print total

def ComparacionNumero():
	layout = [
		[sg.Text('Teclee el primer número')],
		[sg.Input(key='-INPUT1-')],
		[sg.Text('Teclee el segundo numero')],
		[sg.Input(key='-INPUT2-')],
		[sg.Text(key='resultado')],
		[sg.Button('Aceptar'), sg.Button('Salir')],
	]

	window = sg.Window('Comparacion de números', layout, modal = True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		a=(values['-INPUT1-'])
		b=(values['-INPUT2-'])
		if (a < b):
			window['resultado'].update("El número {0} es menor que {1}".format(values['-INPUT1-'], values['-INPUT2-']))
		elif(a > b):
			window['resultado'].update('El numero {0} es mayor que {1}'.format(values['-INPUT1-'], values['-INPUT2-']))
		else:
			window['resultado'].update('Los números son iguales')
	window.close()

def Division():
	layout = [
		[sg.Text('Teclee el dividendo')],
		[sg.Input(key='-Input2-')],
		[sg.Text('Teclee el divisor')],
		[sg.Input(key='-Input1-')],
		[sg.Text(key='resultado')],
		[sg.Button('aceptar'), sg.Button('Salir')],
	]

	window = sg.Window('División', layout, modal = True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'Salir':
			break
		a=float(values['-Input1-'])
		b=float(values['-Input2-'])
		if (a <= 0) or (b <= 0):
			window['resultado'].update('Error: los números deben ser positivos')
		else:
			window['resultado'].update('El resultado es {}'.format(dividir(a,b)))
	window.close()

def dividir(divisor, dividendo):
	return (dividendo/divisor)

def PorcentajeReglaTres():
	layout = [
		[sg.Text('Teclee el total')],
		[sg.Input(key='total')],
		[sg.Text('Teclee la cantidad a calcular')],
		[sg.Input(key='cantidad')],
		[sg.Text(key='resultado')],
		[sg.Button('Aceptar'), sg.Button('Salir')],
	]
	window = sg.Window('Porcentaje en regla de tres', layout, modal = True)
	while True:
		event, values = window.read()
		if event == WINDOW_CLOSED or event == 'Salir':
			break
		total = float(values['total'])
		cantidad = float(values['cantidad'])
		porcentaje = float(total/100)*cantidad
		window['resultado'].update('El porcentaje correspondiente es {}'.format(porcentaje))
	window.close()

def HipotenusaPitagoras():
	layout = [
		[sg.Text('Teclee la longitud del cateto opuesto')],
		[sg.Input(key='CatetoOpuesto')],
		[sg.Text('Teclee la longitud del cateto adyacente')],
		[sg.Input(key='CatetoAdyacente')],
		[sg.Text(key='resultado')],
		[sg.Button('Aceptar'), sg.Button('Salir')],
	]
	window = sg.Window('Hipotenusa en teorema de pitagoras', layout, modal=True)
	while True:
		event, values = window.read()
		if event == WINDOW_CLOSED or event == 'Salir':
			break
		CatetoOpuesto = float(values['CateoOpuesto'])
		CatetoAdyacente = float(values['CatetoAdyacente'])
		hipotenusa = math.sqrt((CatetoOpuesto**2)+(CatetoAdyacente**2))
		window['resultado'].update('La hipotenusa resultante es {}'.format(hipotenusa))
	window.close()

