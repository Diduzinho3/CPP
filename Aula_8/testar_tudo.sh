#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for source in *.cpp; do
  nome="${source%.cpp}"
  echo "[COMPILAR] $source"
  g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror "$source" -o "$tmp/$nome"
  (cd "$tmp" && "./$nome" > "$tmp/$nome.log")
  echo "[OK] $source"
done
echo "12 exercícios compilados e executados com sucesso."
