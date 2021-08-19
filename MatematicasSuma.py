from ModuloMatematicaBasicas import *
import PySimpleGUI as sg

def opciones(evento):
	if evento == 'Suma': suma()
	elif evento == 'Area Rectangulo': areaRectangulo()
	elif evento == 'Multiplicacion': multiplicacion()
	else: return "NA"


#Menu 1
materias = [
				[sg.Button('Matematicas'), sg.Button('Español'), sg.Button('Fisica'), sg.Button('Algebra'), sg.Button('Calculo'), sg.Button('Programacion')],
				[sg.HSeparator()],
				[sg.Button('Suma'), sg.Button('Comparacion Numeros'), sg.Button('Area Rectangulo'), sg.Button('Multiplicacion'),
				 sg.Button('Division'), sg.Button('Porcentaje'), sg.Button('Teorema de pitagoras'), sg.Button('Area Trapecio'), sg.Button('Factorizacion')]
			]
window = sg.Window('SmartVee', materias)

while True: 
	event, values = window.read()
	if event == sg.WINDOW_CLOSED or event == 'Cerrar':
		break

	opciones(event)

	# if event == 'Suma':
	# 	suma()

window.close()



#Menu 2

# tab1 = [
# 		[sg.T('Primer numero')],[sg.I()],
# 		[sg.T('Segundo numero')],[sg.I()],
# 		[sg.Button('=')],
# 		[sg.T('El resultado es: ')]
# 		]
# tab2 = [
# 		[sg.T('Base:')],[sg.I()],
# 		[sg.T('Altura')],[sg.I()],
# 		[sg.Button('=')],
# 		[sg.T('El resultado es: ')]
# 		]
# layout = [
# 			[sg.Button('Matematicas'), sg.Button('Español'), sg.Button('Fisica'), sg.Button('Algebra'), sg.Button('Calculo'), sg.Button('Programacion')],
# 			[sg.TabGroup([[sg.Tab('Suma', tab1), sg.Tab('Area', tab2)]])],
# 			[sg.Button('X')]
# 		]

# window = sg.Window('SmartVee', layout)
# while True:
# 	event, values = window.read()
# 	if event == sg.WINDOW_CLOSED or event == 'X':
# 		break
# window.close()