# Anexo 16: Ajuste Polinómico y Cálculo del Gradiente
import numpy as np
import matplotlib.pyplot as plt

# Datos de los sensores
x = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
y = np.array([28.1, 28.3, 28.2, 28.4, 28.1, 28.2, 28.0, 28.2, 28.1, 28.0])

# Ajuste polinómico de grado 2
coeffs = np.polyfit(x, y, 2)
poly = np.poly1d(coeffs)

# Gradiente
poly_derivative = poly.deriv()
gradients = poly_derivative(x)

print(f"Ecuacion: y = {coeffs[0]:.3f}x^2 + {coeffs[1]:.3f}x + {coeffs[2]:.3f}")

plt.scatter(x, y, color='red', label='Datos reales')
plt.plot(x, poly(x), label='Ajuste')
plt.legend()
plt.show()
