import PySimpleGUI as sg
from PySimpleGUI.PySimpleGUI import Window


def suma():
	layout = [
			[sg.Text("Primer numero: ")],
			[sg.Input(key='-INPUT1-')],
			[sg.Text("Segundo numero: ")],
			[sg.Input(key='-INPUT2-')],	
			[sg.T(key='Resultado')],
			[sg.Button('Ok'), sg.Button('Salir')]
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
			[sg.B('OK'), sg.B('X')]
		]
	window = sg.Window('Area Rectangulo', layout, modal=True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == 'X':
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
				[sg.B('OK'), sg.B(' X ')]
			]
	window = sg.Window("Multiplicacion", layout, modal=True)
	while True:
		event, values = window.read()
		if event == sg.WINDOW_CLOSED or event == ' X ':
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