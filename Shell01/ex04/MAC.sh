#!/bin/sh
ifconfig | grep "ether " | awk '{print $2}'
#ifconfig lista todo dispositos de conecao com internet
#|
#grep "ether " filtra apenas ether lista que contem enderecos mac
#|
#akw '{print $2}' imprime apenas segunda coluna resultante do grep
