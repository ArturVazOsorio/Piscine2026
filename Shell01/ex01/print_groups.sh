id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'

id -Gn #Procurar grupo e nome de user
$FT_USER #Ler uma variavel de ambiente passada

| #executa outro programas usando saida anterior
tr #utilitario para formatar texto
tr ' ' ','  #substitui espaco por virgula
tr -d '\n' #deleta newline comman
