#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

class VentanaNotas : public QWidget {
public:
    VentanaNotas(QWidget *parent = nullptr) : QWidget(parent) {
        // Etiquetas y campos de entrada
        QLabel *labelDeberes = new QLabel("Deberes:", this);
        inputDeberes = new QLineEdit(this);

        QLabel *labelTrabajos = new QLabel("Trabajos:", this);
        inputTrabajos = new QLineEdit(this);

        QLabel *labelPruebas = new QLabel("Pruebas:", this);
        inputPruebas = new QLineEdit(this);

        QLabel *labelExamenes = new QLabel("Exámenes:", this);
        inputExamenes = new QLineEdit(this);

        // Botón para calcular el promedio
        QPushButton *botonCalcular = new QPushButton("Calcular Promedio", this);
        connect(botonCalcular, &QPushButton::clicked, this, &VentanaNotas::calcularPromedio);

        // Layout para organizar los widgets
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(labelDeberes);
        layout->addWidget(inputDeberes);
        layout->addWidget(labelTrabajos);
        layout->addWidget(inputTrabajos);
        layout->addWidget(labelPruebas);
        layout->addWidget(inputPruebas);
        layout->addWidget(labelExamenes);
        layout->addWidget(inputExamenes);
        layout->addWidget(botonCalcular);

        setLayout(layout);
    }

private slots:
    void calcularPromedio() {
        bool ok1, ok2, ok3, ok4;

        // Obtener las notas desde las entradas
        double notaDeberes = inputDeberes->text().toDouble(&ok1);
        double notaTrabajos = inputTrabajos->text().toDouble(&ok2);
        double notaPruebas = inputPruebas->text().toDouble(&ok3);
        double notaExamenes = inputExamenes->text().toDouble(&ok4);

        // Verificar si las entradas son válidas
        if (!ok1 || !ok2 || !ok3 || !ok4) {
            QMessageBox::critical(this, "Error", "Error: Ingrese notas válidas.");
            return;
        }

        // Verificar que las notas estén dentro del rango permitido (1 a 10)
        if (notaDeberes < 1 || notaDeberes > 10 ||
            notaTrabajos < 1 || notaTrabajos > 10 ||
            notaPruebas < 1 || notaPruebas > 10 ||
            notaExamenes < 1 || notaExamenes > 10) {
            QMessageBox::critical(this, "Error", "Las notas deben estar entre 1 y 10.");
            return;
        }

        // Calcular el promedio
        double promedio = (notaDeberes + notaTrabajos + notaPruebas + notaExamenes) / 4;

        // Determinar el estado académico
        QString estado;
        if (promedio > 7) {
            estado = "Aprobado";
        } else if (promedio >= 6) {
            estado = "Reprueba";
        } else {
            estado = "Pierde";
        }

        // Mostrar el resultado en un cuadro de diálogo
        QMessageBox::information(this, "Resultado", QString("Promedio: %1\nEstado: %2").arg(promedio).arg(estado));
    }

private:
    QLineEdit *inputDeberes;
    QLineEdit *inputTrabajos;
    QLineEdit *inputPruebas;
    QLineEdit *inputExamenes;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VentanaNotas ventana;
    ventana.setWindowTitle("Cálculo de Promedio");
    ventana.resize(300, 200);
    ventana.show();

    return app.exec();
}