#!/usr/bin/env bash
# Compila e verifica automaticamente todos os exercicios.
set -euo pipefail
cd "$(dirname "$0")"
PASTA_TEMP="$(mktemp -d)"
trap 'rm -rf "$PASTA_TEMP"' EXIT

compilar() {
  local arquivo="$1" saida="$2"
  shift 2
  g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror "$@" "$arquivo" -o "$PASTA_TEMP/$saida"
}

verificar() {
  local nome="$1" saida="$2" esperado="$3"
  if ! grep -Fq -- "$esperado" <<< "$saida"; then
    printf 'FALHA (%s): nao encontrei [%s]\n' "$nome" "$esperado" >&2
    printf 'Saida: %s\n' "$saida" >&2
    exit 1
  fi
}

for n in 01 02 03 04 05 06 07 08; do
  arquivo="$(find . -maxdepth 1 -name "${n}_*.cpp" -print -quit)"
  compilar "$arquivo" "exe$n"
  echo "OK: compilacao do exercicio $n"
done

saida="$($PASTA_TEMP/exe01)"; verificar '01' "$saida" 'Marca: Toyota'; verificar '01' "$saida" 'Numero de portas: 4'
saida="$($PASTA_TEMP/exe02)"; verificar '02' "$saida" 'Veiculo: ruido generico'; verificar '02' "$saida" 'Carro: bi-bi!'; verificar '02' "$saida" 'Motocicleta: vruuum!'
saida="$($PASTA_TEMP/exe03)"; verificar '03' "$saida" 'Nome (public): Ana'; verificar '03' "$saida" 'Salario (protected): R$ 5500'; verificar '03' "$saida" 'Documento (via metodo publico): DOC-123'
saida="$($PASTA_TEMP/exe04)"; verificar '04' "$saida" 'COM virtual: vinculacao DINAMICA'; verificar '04' "$saida" 'Carro: bi-bi!'; verificar '04' "$saida" 'Motocicleta: vruuum!'
compilar '04_polimorfismo.cpp' 'exe04_sem_virtual' -DSEM_VIRTUAL
saida="$($PASTA_TEMP/exe04_sem_virtual)"; verificar '04 sem virtual' "$saida" 'SEM virtual: vinculacao ESTATICA'
qtd="$(grep -Fc 'Veiculo: ruido generico do motor.' <<< "$saida")"
[[ "$qtd" == 3 ]] || { echo 'FALHA: vinculacao estatica deveria chamar a base 3 vezes' >&2; exit 1; }
echo 'OK: comparacao da vinculacao estatica/dinamica (04)'
saida="$($PASTA_TEMP/exe05)"; verificar '05' "$saida" 'Retangulo | Area: 12.00 | Perimetro: 14.00'; verificar '05' "$saida" 'Circulo | Area: 12.57 | Perimetro: 12.57'
saida="$($PASTA_TEMP/exe06)"; verificar '06' "$saida" 'Destrutor RecursoArquivo: buffer'; verificar '06' "$saida" 'Destrutor Recurso: parte base liberada.'
saida="$($PASTA_TEMP/exe07)"; verificar '07' "$saida" 'Mesma instancia de Dispositivo? true'; verificar '07' "$saida" 'Identificador: 303'
compilar '07_diamante.cpp' 'exe07_sem_virtual' -DSEM_HERANCA_VIRTUAL
saida="$($PASTA_TEMP/exe07_sem_virtual)"; verificar '07 sem virtual' "$saida" 'Mesma instancia de Dispositivo? false'; verificar '07 sem virtual' "$saida" 'Identificador: 101'; verificar '07 sem virtual' "$saida" 'Identificador: 202'
echo 'OK: comparacao do diamante (07)'
saida="$($PASTA_TEMP/exe08)"; verificar '08' "$saida" 'Email para'; verificar '08' "$saida" 'SMS para'; verificar '08' "$saida" 'Push em'
echo 'OK: todas as verificacoes de execucao passaram.'
