from ModuloMatematicaBasicas import *
import PySimpleGUI as sg

def submenu(evento):
	if evento == 'Matematicas': 
		window['_suma_'].update(visible=True)
		window['_comparacion_'].update(visible=True)
		window['_areaRect_'].update(visible=True)
		window['_multiplicacion_'].update(visible=True)
		window['_division_'].update(visible=True)
		window['_porcentaje_'].update(visible=True)
		window['_pitagoras_'].update(visible=True)
		window['_areaTrap_'].update(visible=True)
		window['_factorizacion_'].update(visible=True)
	else:
		window['_suma_'].update(visible=False)
		window['_comparacion_'].update(visible=False)
		window['_areaRect_'].update(visible=False)
		window['_multiplicacion_'].update(visible=False)
		window['_division_'].update(visible=False)
		window['_porcentaje_'].update(visible=False)
		window['_pitagoras_'].update(visible=False)
		window['_areaTrap_'].update(visible=False)
		window['_factorizacion_'].update(visible=False)

	if evento == 'Español': 
		window['_lectura_'].update(visible=True)
		window['_comprension_'].update(visible=True)
	else:
		window['_lectura_'].update(visible=False)
		window['_comprension_'].update(visible=False)

	if evento == 'Fisica': 
		window['_parabolico_'].update(visible=True)
		window['_calor_'].update(visible=True)
	else:
		window['_parabolico_'].update(visible=False)
		window['_calor_'].update(visible=False)


def opciones(evento):
	if evento == '_suma_': general('Suma', suma, '+')
	elif evento == '_areaRect_': areaRectangulo()
	elif evento == '_multiplicacion_': general('Multiplicacion', multiplicacion, '*')
	elif evento == '_comparacion_': ComparacionNumero()
	elif evento == '_division_': general('Division', dividir, '/')
	elif evento == '_porcentaje_': PorcentajeReglaTres()
	elif evento == '_pitagoras_': HipotenusaPitagoras()
	# elif evento == '_areaTrap_':
	# elif evento == '_factorizacion_': PorcentajeReglaTres()
	else: return "NA"

#Menu 1
	# materias = [
	# 	[sg.Button('Matematicas'), sg.Button('Español'), sg.Button('Fisica'), sg.Button('Algebra'), sg.Button('Calculo'), sg.Button('Programacion')],
	# 	[sg.HSeparator()],
	# 	[sg.Button('Suma'), sg.Button('Comparacion Numeros'), sg.Button('Area Rectangulo'), sg.Button('Multiplicacion'),
	# 	sg.Button('Division'), sg.Button('Porcentaje'), sg.Button('Teorema de pitagoras'), sg.Button('Area Trapecio'), sg.Button('Factorizacion')]
	# #	[sg.VSeparator()],
	# #	[sg.Button('Hipotenusa'), sg.Button('Catetos')],
	# ]
	# window = sg.Window('SmartBee', materias)

	# while True: 
	# 	event, values = window.read()
	# 	if event == sg.WINDOW_CLOSED or event == 'Cerrar':
	# 		break

	# 	opciones(event)	

	# window.close()

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

#Menu 3
materias = [[sg.Button('Matematicas'), sg.Button('Español'), sg.Button('Fisica'), sg.Button('Algebra'), sg.Button('Calculo'), sg.Button('Programacion')]]

subTemas = [ [sg.pin(sg.Button('Suma', key = '_suma_', visible=False)),
            		sg.pin(sg.Button('Comparacion de numeros', key = '_comparacion_', visible=False)),
                	sg.pin(sg.Button('Area Rectangulo', key = '_areaRect_', visible=False)),
                	sg.pin(sg.Button('Multiplicacion', key = '_multiplicacion_', visible=False)),
                	sg.pin(sg.Button('Division', key = '_division_', visible=False)),
                	sg.pin(sg.Button('Porcentaje', key = '_porcentaje_', visible=False)),
                	sg.pin(sg.Button('Teorema de pitagoras', key = '_pitagoras_', visible=False)),
                	sg.pin(sg.Button('Area Trapecio', key = '_areaTrap_', visible=False)),
                	sg.pin(sg.Button('Factorizacion', key = '_factorizacion_', visible=False)),
                	sg.pin(sg.Button('Lectura', key = '_lectura_', visible=False)),
                	sg.pin(sg.Button('Comprension', key = '_comprension_', visible=False)),
                	sg.pin(sg.Button('Tiro parabolico', key = '_parabolico_', visible=False)),
                	sg.pin(sg.Button('Calor y temperatura', key = '_calor_', visible=False)),
                	]]

layout = [materias, subTemas]

window = sg.Window('SmartBee', layout)

while True: 
	event, values = window.read()
	if event == sg.WINDOW_CLOSED or event == 'Cerrar':
		break

	submenu(event)
#	print(event)
	opciones(event)
	

window.close()

