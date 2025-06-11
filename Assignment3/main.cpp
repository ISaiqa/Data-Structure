#include <iostream>
#include"Graph.h"



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	string userName;
    cout << "Welcome to Flight Route Optimizer!\n";
    
    
    cout << "Enter number of cities (0-20): ";
    int numCities;
    cin >> numCities;
    if (numCities < 0 || numCities > 20) {
        cout << "\tError: Enter 0-20 only!\n";
        return 0;
    }
    
    Graph g(numCities);
    
    int choice;
    do {
    	
        cout << "\n~~~~ Menu ~~~~\n";
        cout << "1) Add Route\n";
        cout << "2) Remove Route\n";
        cout << "3) Add City\n";
        cout << "4) Remove City\n";
        cout << "5) Compute Shortest Distance\n";
        cout << "6) Display Routes\n";
        cout << "7) Exit\n";
        cout << "Enter Choice (1-7): ";
        cin >> choice;
        
        switch (choice) {
            case 1: 
			{
                int src, dst;
                float distance;
                cout << "Enter source city (0-" << g.getVertices()-1 << "): ";
                cin >> src;
                if (src < 0 || src >= g.getVertices()) {
                    cout << "\tError: City not found!\n";
                    break;
                }
                cout << "Enter destination city (0-" << g.getVertices()-1 << "): ";
                cin >> dst;
                if (dst < 0 || dst >= g.getVertices()) {
                    cout << "\tError: City not found!\n";
                    break;
                }
                cout << "Enter distance (km): ";
                cin >> distance;
                if (distance <= 0) {
                    cout << "\tError: Distance must be positive!\n";
                    break;
                }
                g.addRoute(src, dst, distance);
                cout << "\tRoute added!\n";
                cout << "\t~~~~ Routes ~~~~\n";
                g.printGraph();
                break;
            }
            case 2: {
                int src, dst;
                cout << "Enter source city (0-" << g.getVertices()-1 << "): ";
                cin >> src;
                if (src < 0 || src >= g.getVertices()) {
                    cout << "\tError: City not found!\n";
                    break;
                }
                cout << "Enter destination city (0-" << g.getVertices()-1 << "): ";
                cin >> dst;
                if (dst < 0 || dst >= g.getVertices()) {
                    cout << "\tError: City not found!\n";
                    break;
                }
                g.removeRoute(src, dst);
                cout << "\tRoute removed!\n";
                cout << "\t~~~~ Routes ~~~~\n";
                g.printGraph();
                break;
            }
            case 3: {
                g.addCity();
                cout << "\tCity added!\n";
                break;
            }
            case 4: {
                int city;
                cout << "Enter city to remove (0-" << g.getVertices()-1 << "): ";
                cin >> city;
                if (city < 0 || city >= g.getVertices()) {
                    cout << "\tError: City not found!\n";
                    break;
                }
                g.removeCity(city);
                cout << "\tCity routes removed!\n";
                cout << "\t~~~~ Routes ~~~~\n";
                g.printGraph();
                break;
            }
            
            case 5: {
            int src;
            cout << "Enter source city (0-" << g.getVertices() - 1 << "): ";
            cin >> src;
            if (src < 0 || src >= g.getVertices()) {
                cout << "\tError: City not found!\n";
                break;
            }
            g.dijkstra(src);
            cout << "\tPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        }
            case 6: {
                cout << "\t~~~~ Routes ~~~~\n";
                g.printGraph();
                break;
            }
            case 7: {
                cout << "\n~~~~ Summary  ~~~~\n";
                g.printGraph();
                
                cout << "Thanks for using Flight Route Optimizer!\n";
                return 0;
            }
            default: {
                cout << "\tOops! Pick 1-7 only.\n";
            }
        }
        
    } while (true);
    
    return 0;

}