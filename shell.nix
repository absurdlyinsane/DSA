{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell rec {
  buildInputs = with pkgs; [
    gcc
    gdb
    libcxx
    clang
  ];
}