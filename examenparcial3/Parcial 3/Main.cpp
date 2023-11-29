#include <windows.h>
#include <stdio.h>
#include "resource.h"

#define USER "Stacy"
#define PSWRD "uanl"


struct evento {
    char fecha[100], hora[100], nombre[50], recinto[50], lugar[50];
    int nume;
    evento* ant,*sig;
};

evento* inicio, * aux, * fin = NULL;
char fechaf[100] = {0}; char horaf[100]; char nombref[50]; char recintof[50]; char lugarf[50]; int num;
char fechad[100] = { 0 }; char horad[100]; char nombred[50]; char contrasena[50] = {0};char recintod[50]; char lugard[50]; 
evento* nodo_evento = new evento;

HINSTANCE hInstGlob = 0;

LRESULT CALLBACK InicioSesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Menu(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Descuentos(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hwnd;
    MSG mensaje;
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(ID_PROMOCIONES), NULL, Descuentos);
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(103), NULL, Menu);
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(101), NULL, InicioSesion);
    ShowWindow(hwnd, SW_SHOWDEFAULT);


    while (TRUE == GetMessage(&mensaje, 0, 0, 0))
    {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }

    return mensaje.wParam;
}
int totfinal = 0;
char precio[150] = {};
int res = 0; int subtotal = 0; float total = 0; int recuperar = 0;
int preciO = 1040; int preciO1 = 810; int preciO2 = 460;
int cont = 0; int boletos = 0; int boletos1 = 0;


LRESULT CALLBACK InicioSesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND: {
        if (LOWORD(wParam) == ID_BOTON_INGRESAR_LOGIN)
        {
            HWND hwndUserEdit = GetDlgItem(hwnd, ID_EDIT_USUARIO_LOGIN);
            HWND hwndPassEdit = GetDlgItem(hwnd, ID_EDIT_CONTRA_LOGIN);
            char userBuffer[256];
            char passBuffer[256];
            GetWindowText(hwndUserEdit, userBuffer, sizeof(userBuffer));
            GetWindowText(hwndPassEdit, passBuffer, sizeof(passBuffer));

            // Verificar si los valores coinciden con los definidos
            if (strcmp(userBuffer, USER) == 0 && strcmp(passBuffer, PSWRD) == 0) {
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(ID_PANTALLA_INICIO), NULL, Menu);
                
            }
            else {
                MessageBox(hwnd, "Usuario o contraseña incorrectos", "Error", MB_ICONERROR);
            }
        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}
LRESULT CALLBACK Menu(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    char fechaf[] = "29/11/2023";
    char horaf[] = "20:00";
    char nombref[] = "Basic Boys";
    char recintof[] = "Teatro General Licenciado Vasconselos";
    char lugarf[] = "Hidalgo, Nuevo Leon";
    int num = 1;
    
    switch (msg)
    {
    case WM_INITDIALOG: {

        EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), FALSE);

        SetWindowText(GetDlgItem(hwnd, 1013), nombref);
        SetWindowText(GetDlgItem(hwnd, 1014), fechaf);
        SetWindowText(GetDlgItem(hwnd, 1015), horaf);
        SetWindowText(GetDlgItem(hwnd, 1016), recintof);
        SetWindowText(GetDlgItem(hwnd, 1017), lugarf);

        char fechaf[] = "30/11/2023";
        char horaf[] = "18:30";
        char nombref[] = "Basic Domes";
        char recintof[] = "Domo Care";
        char lugarf[] = "Apodaca, Nuevo León";
        SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO2_NOMBRE), nombref);
        SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO2_FECHA), fechaf);
        SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO2_HORA), horaf);
        SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO2_RECINTO), recintof);
        SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO2_LUGAR), lugarf);

        SetWindowText(GetDlgItem(hwnd, ID_EDIT_NUM_PAG), "1");

       

    }break;
    case WM_COMMAND: {
        if (LOWORD(wParam) == ID_BOTON_VENTA_PI)
        {
            MessageBox(hwnd, "Debe seleccionar un evento", "Aviso", MB_OK | MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == ID_BOTON_SIGUIENTE)
        {
            char fechaf[] = "1/12/2023";
            char horaf[] = "21:00";
            char nombref[] = "MINIONS STACY´S VERSION";
            char recintof[] = "TEATRO GASPAR DE GANTE";
            char lugarf[] = "China, Nuevo Leon";

            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_NOMBRE), nombref);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_FECHA), fechaf);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_HORA), horaf);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_RECINTO), recintof);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_LUGAR), lugarf);

            ShowWindow(GetDlgItem(hwnd, ID_BOTON_SIGUIENTE), SW_HIDE);
            ShowWindow(GetDlgItem(hwnd, ID_BOTON_ANTERIOR), SW_SHOW);
            ShowWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAR2), SW_HIDE);

            for (int i = ID_EDIT_EVENTO2_NOMBRE; i < ID_BOTON_COMPRAR2; i++)
            {
                
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }

            SetWindowText(GetDlgItem(hwnd, ID_EDIT_NUM_PAG), "2");
        }
        if (LOWORD(wParam) == ID_BOTON_ANTERIOR)
        {
            char fechaf[] = "25/11/2023";
            char horaf[] = "20:30";
            char nombref[] = "The Warning";
            char recintof[] = "Teatro Morelos";
            char lugarf[] = "Toluca, Estado de México";

                SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_NOMBRE), nombref);
                SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_FECHA), fechaf);
                SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_HORA), horaf);
                SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_RECINTO), recintof);
                SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_LUGAR), lugarf);

                ShowWindow(GetDlgItem(hwnd, ID_BOTON_ANTERIOR), SW_HIDE);
                ShowWindow(GetDlgItem(hwnd, ID_BOTON_SIGUIENTE), SW_SHOW);

                for (int i = ID_EDIT_EVENTO2_NOMBRE; i < ID_BOTON_COMPRAR2; i++)
                {
                    ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
                }
                SetWindowText(GetDlgItem(hwnd, ID_EDIT_NUM_PAG), "1");

                ShowWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAR2), SW_SHOW);
        }
        if (LOWORD(wParam) == ID_BOTON_COMPRAR1 )
        {
            cont = 0;
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), FALSE);
            for (int i = ID_BOTON_COMPRAR1; i < ID_STATIC_TITULO_VENTA; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = ID_STATIC_MISCOMPRAS; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            
            for (int i = ID_LIST_EVENTOS; i < 1041; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            
            char VIP[150] = "VIP de pie      ADULTOS   $1,040.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)VIP);
            //preciO = 1040;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO);

            char BUTACAS[150] = "Butacas         ADULTOS   $810.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)BUTACAS);
            //preciO1 = 810;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO1);

            char GRAL[150] = "General          ADULTOS   $460.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)GRAL);
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 1, (LPARAM)preciO2);
            res = 0;
            SetDlgItemInt(hwnd, ID_EDIT_CANTIDAD, res, TRUE);

            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_NOMBRE, nombred, sizeof(nombred));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_FECHA, fechad, sizeof(fechad));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_HORA, horad, sizeof(horad));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_RECINTO, recintod, sizeof(recintod));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_LUGAR, lugard, sizeof(lugard));
        }
        if (LOWORD(wParam) == ID_BOTON_COMPRAR2)
        {
            cont = 0;
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), FALSE);
            for (int i = ID_BOTON_COMPRAR1; i < ID_STATIC_TITULO_VENTA; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = ID_STATIC_MISCOMPRAS; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = ID_EDIT_EVENTO1_NOMBRE; i < ID_BOTON_COMPRAR1; i++)
            {
                SetWindowText(GetDlgItem(hwnd, i), " ");

            }
            
            GetDlgItemText(hwnd, ID_EDIT_EVENTO2_NOMBRE, nombref, sizeof(nombref));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO2_FECHA, fechaf, sizeof(fechaf));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO2_HORA, horaf, sizeof(horaf));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO2_RECINTO, recintof, sizeof(recintof));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO2_LUGAR, lugarf, sizeof(lugarf));
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_NOMBRE), nombref);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_FECHA), fechaf);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_HORA), horaf);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_RECINTO), recintof);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_LUGAR), lugarf);

            for (int i = ID_LIST_EVENTOS; i < 1041; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char VIP[150] = "VIP de pie      ADULTOS   $1,040.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)VIP);
            //preciO = 1040;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO);

            char BUTACAS[150] = "Butacas         ADULTOS   $810.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)BUTACAS);
            //preciO1 = 810;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO1);

            char GRAL[150] = "General          ADULTOS   $460.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)GRAL);
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 1, (LPARAM)preciO2);

            res = 0;
            SetDlgItemInt(hwnd, ID_EDIT_CANTIDAD, res, TRUE);

            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_NOMBRE, nombred, sizeof(nombred));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_FECHA, fechad, sizeof(fechad));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_HORA, horad, sizeof(horad));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_RECINTO, recintod, sizeof(recintod));
            GetDlgItemText(hwnd, ID_EDIT_EVENTO1_LUGAR, lugard, sizeof(lugard));
        }
        if (LOWORD(wParam == ID_REALIZAR_COMPRA))
        {
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAS_PI), TRUE);
            res = GetDlgItemInt(hwnd, ID_EDIT_CANTIDAD, NULL, TRUE);
            boletos = res;
            boletos1 = res;
            if (res == 0) {
                MessageBox(hwnd, "Debe ingresar la cantidad de boletos", "Aviso", MB_OK | MB_ICONINFORMATION);
            }
            else
            {
                int idx = SendDlgItemMessage(hwnd, ID_LIST_EVENTOS, LB_GETCURSEL, 0, 0);
                int numc = SendDlgItemMessage(hwnd, ID_LIST_EVENTOS, LB_GETITEMDATA, idx, 0);
                recuperar = numc;
                subtotal = numc * res;
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(ID_PROMOCIONES), NULL, Descuentos);
            }

            
        }
        if (LOWORD(wParam) == ID_BOTON_EVENTOS_PI)
        {

            EnableWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), FALSE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), TRUE);
            for (int i = ID_STATIC_MISCOMPRAS; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = ID_STATIC_TITULO_VENTA; i < ID_BOTON_DOSPORUNO; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = ID_BOTON_COMPRAR1; i < ID_STATIC_TITULO_VENTA; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char fechaf[] = "25/11/2023";
            char horaf[] = "20:30";
            char nombref[] = "The Warning";
            char recintof[] = "Teatro Morelos";
            char lugarf[] = "Toluca, Estado de México";

            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_NOMBRE), nombref);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_FECHA), fechaf);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_HORA), horaf);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_RECINTO), recintof);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_LUGAR), lugarf);
        }
        if (LOWORD(wParam) == ID_BOTON_COMPRAS_PI)
        {
            if(cont==1||cont==2){
            for (int i = ID_BOTON_COMPRAR1; i < ID_BOTON_DOSPORUNO; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAS_PI), FALSE);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_NOMBRE), nombred);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_FECHA), fechad);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_HORA), horad);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_RECINTO), recintod);
            SetWindowText(GetDlgItem(hwnd, ID_EDIT_EVENTO1_LUGAR), lugard);
            

            for (int i = ID_STATIC_MISCOMPRAS; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            SetDlgItemInt(hwnd, ID_EDIT_MISCOMPRAS_BOLETOS,boletos1, TRUE);
            SetDlgItemInt(hwnd, ID_EDIT_MISCOMPRAS_TOTAL,totfinal, TRUE);
            }
            else if (cont == 0) {
                MessageBox(hwnd, "No ha realizado ninguna compra", "Aviso", MB_OK | MB_ICONINFORMATION);
            }
        }
        if (LOWORD(wParam) == ID_BOTON_SALIR_PI)
        {
            DestroyWindow(hwnd);
            PostQuitMessage(0);
        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}
char numC[16] = { 0 };
LRESULT CALLBACK Descuentos(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG: {
        
        

        //descuento 2x1
        total = subtotal + (subtotal * 0.16);
        sprintf_s(numC, "%.3f", total);
        SetDlgItemText(hwnd, ID_EDIT_TOTAL_COMPRA, numC);
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Ninguno");

        
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Ticket 2x1");
        int precio3 = 1;
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), CB_SETITEMDATA, -1, (LPARAM)precio3);
        // ningun descuento
        int precio1 = 2;
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), CB_SETITEMDATA, 0, (LPARAM)precio1);
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"10%");

        //10% de descuento
        int precio2 = 3;
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), CB_SETITEMDATA, 0, (LPARAM)precio2);
        SendMessage(GetDlgItem(hwnd, IDC_COMBO2), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Tarjeta de debito");
        SendMessage(GetDlgItem(hwnd, IDC_COMBO2), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Tarjeta de crédito");
        SendMessage(GetDlgItem(hwnd, IDC_COMBO2), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Paypal");
        res = 0;
        SetDlgItemInt(hwnd, ID_EDIT_TARJETA_COMPRA, res, TRUE);
        SetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, res, TRUE);
        SetDlgItemInt(hwnd, ID_EDIT_USUARIO_COMPRA, res, TRUE);

    }break;
    case WM_COMMAND: {
        if (LOWORD(wParam) == ID_BOTON_DOSPORUNO)
        {
            int idx = SendDlgItemMessage(hwnd, ID_COMBO_DESCUENTOS, CB_GETCURSEL, 0, 0);
            int numc = SendDlgItemMessage(hwnd, ID_COMBO_DESCUENTOS, CB_GETITEMDATA, idx, 0);
            SetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, numc, TRUE);
            if (numc == 1)
            {
                if (boletos % 2 == 0)
                {
                    boletos = boletos / 2;
                    subtotal =boletos * recuperar;
                    total = subtotal + (subtotal * 0.16);
                    sprintf_s(numC, "%.3f", total);
                    SetDlgItemText(hwnd, ID_EDIT_TOTAL_COMPRA, numC);
                }
                
            }
            if (numc == 3)
            {
                total = subtotal - (subtotal * 0.10);
                sprintf_s(numC, "%.3f", total);
                SetDlgItemText(hwnd, ID_EDIT_TOTAL_COMPRA, numC);
            }
        }
        if (LOWORD(wParam) == ID_BOTON_ACEPTAR_COMPRA)
        {
            totfinal = total;
            cont = 1;
            int res3 = GetDlgItemInt(hwnd, ID_EDIT_TARJETA_COMPRA, NULL, TRUE);
            int res1= GetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, NULL, TRUE);
      
            if (res3 == 0||res1==0) {
                MessageBox(hwnd, "Debe ingresar todos los datos", "Aviso", MB_OK | MB_ICONINFORMATION);
            }
            else
            {
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(ID_PANTALLA_INICIO), NULL, Menu);
            }
            
        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}

void  agregar_evento(evento* nuevo) {
    if (inicio == NULL) {
        inicio = new evento;
        aux = inicio;

        aux->sig = NULL;
        aux->ant = NULL;

        strcpy_s(aux->fecha, nuevo->fecha);
        strcpy_s(aux->hora, nuevo->hora);
        strcpy_s(aux->nombre, nuevo->nombre);
        strcpy_s(aux->recinto, nuevo->recinto);
        strcpy_s(aux->lugar, nuevo->lugar);
        aux->nume = nuevo->nume;

    }
    else {
        aux = inicio;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new evento;
        aux->sig->sig = NULL;
        aux->sig->ant = aux;
        aux = aux->sig;
        fin = aux;
        strcpy_s(aux->fecha, nuevo->fecha);
        strcpy_s(aux->hora, nuevo->hora);
        strcpy_s(aux->nombre, nuevo->nombre);
        strcpy_s(aux->recinto, nuevo->recinto);
        strcpy_s(aux->lugar, nuevo->lugar);
        aux->nume = nuevo->nume;
    }
}