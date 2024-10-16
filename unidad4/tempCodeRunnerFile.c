  do{
            printf("Ingrese el numero del cliente\n");
            scanf("%d",&aux);
        }while(((aux < 1000 || aux > 9999) || buscar(cli, aux, cant) == -1) && aux != 999);