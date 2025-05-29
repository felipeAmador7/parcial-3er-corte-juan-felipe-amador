#include <iostream>


using namespace std;

int main() {

    bool enbatalla = true;
    bool turnojugador = true;

    int vidajugador = 100;
    int vidarival = 100;

    while (enbatalla) {
        if (turnojugador) {
            cout << "Nota: Para escribir frases, en lugar de usar space usa _" << endl;
            cout << "---Selecciona una acción---" << endl;
            cout << "Atacar" << endl;
            cout << "Bolsa" << endl;
            cout << "Huir" << endl;
            cout << "Pokémon" << endl;

            string eleccion;
            cin >> eleccion;

            if (eleccion == "Atacar") {
                cout << "Elige un ataque: " << endl;
                cout << "Cola_de_hierro" << endl;
                cout << "Esfera_aural" << endl;
                cout << "Bola_sombra" << endl;
                cout << "Puño_trueno" << endl;

                string ataque;
                cin >> ataque;

                if (ataque == "Cola_de_hierro") {
                    cout << "Lucario ha usado Cola de Hierro" << endl;
                    vidarival -= 30;
                    turnojugador = false;
                } else if (ataque == "Esfera_aural") {
                    cout << "Lucario ha usado Esfera Aural" << endl;
                    vidarival -= 50;
                    turnojugador = false;
                } else if (ataque == "Bola_sombra") {
                    cout << "Lucario ha usado Bola Sombra" << endl;
                    vidarival -= 40;
                    turnojugador = false;
                } else if (ataque == "Puño_trueno") {
                    cout << "Lucario ha usado Puño Trueno" << endl;
                    vidarival -= 35;
                    turnojugador = false;
                } else {
                    cout << "Error: ataque no válido" << endl;
                }

            } else if (eleccion == "Bolsa") {
                cout << "Botiquin" << endl;
                cout << "Objetos" << endl;

                string bolsa;
                cin >> bolsa;

                if (bolsa == "Botiquin") {
                    cout << "Selecciona una curación: " << endl;
                    cout << "Revivir" << endl;
                    cout << "Pocion_maxima" << endl;
                    cout << "Restaurar_todo" << endl;
                    cout << "Pocion" << endl;

                    string curacion;
                    cin >> curacion;

                    if (curacion == "Revivir") {
                        if (vidajugador < 1) {
                            vidajugador = 100;
                            cout << "Has revivido a Lucario" << endl;
                            turnojugador = false;
                        } else {
                            cout << "No puedes revivir a Lucario" << endl;
                        }

                    } else if (curacion == "Pocion_maxima") {
                        cout << "Lucario ha restaurado todos sus PS" << endl;
                        vidajugador = 100;
                        turnojugador = false;

                    } else if (curacion == "Restaurar_todo") {
                        cout << "Lucario ha vuelto a su estado normal" << endl;
                        vidajugador = 100;
                        turnojugador = false;

                    } else if (curacion == "Pocion") {
                        cout << "Has usado una poción en Lucario" << endl;
                        vidajugador += 20;
                        if (vidajugador > 100) vidajugador = 100;
                        turnojugador = false;

                    } else {
                        cout << "Error, opción no válida" << endl;
                    }
                }

            } else if (eleccion == "Huir") {
                cout << "¿Estás seguro que quieres huir? (Si / No)" << endl;

                string huir;
                cin >> huir;

                if (huir == "Si") {
                    cout << "Has huido del combate" << endl;
                    enbatalla = false;
                } else if (huir == "No") {
                    cout << "Has vuelto al combate" << endl;
                } else {
                    cout << "Opción inválida" << endl;
                }

            } else if (eleccion == "Pokémon") {
                cout << "Elige un Pokémon" << endl;
                cout << "Lucario" << endl;
                // No se cambia el turno aquí porque no se ejecuta acción real

            } else {
                cout << "Error, opción no válida" << endl;
            }

        } else {
            // Turno del rival
            cout << "El Pokémon rival ha usado un ataque" << endl;
            vidajugador -= 40;
            cout << "Lucario ha recibido 20 de daño. PS actuales: " << vidajugador << endl;
            turnojugador = true;
        }

        if (vidajugador <= 0) {
            cout << "Has perdido el combate :(" << endl;
            enbatalla = false;
        } else if (vidarival <= 0) {
            cout << "Has ganado el combate!!!" << endl;
            enbatalla = false;
        }
    }

    return 0;
}

