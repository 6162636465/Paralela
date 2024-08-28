import matplotlib.pyplot as plt

# Datos
sizes = [300, 900, 1500]
blocks_times = [156, 4100, 18479]  # Tiempos en milisegundos para la multiplicación por bloques
classic_times = [179.013, 4828.89, 24627]  # Tiempos en milisegundos para la multiplicación clásica

# Crear el gráfico
plt.figure(figsize=(10, 6))

# Graficar los tiempos de ejecución
plt.plot(sizes, blocks_times, marker='o', linestyle='-', color='b', label='Bloques')
plt.plot(sizes, classic_times, marker='o', linestyle='--', color='r', label='Clásico')

# Etiquetas y título
plt.xlabel('Tamaño de la matriz')
plt.ylabel('Tiempo de ejecución (milisegundos)')
plt.title('Comparación del tiempo de ejecución de la multiplicación de matrices')
plt.legend()
plt.grid(True)

# Mostrar el gráfico
plt.show()
