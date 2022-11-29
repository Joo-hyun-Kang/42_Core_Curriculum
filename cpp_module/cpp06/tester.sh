#!/bin/bash

echo "input: <0> "
./parser 0

echo "input: <10.0>"
./parser 10.0

echo "input: <1000>"
./parser 1000

echo "input: <f>"
./parser f

echo "input: <42.0f>"
./parser 42.0f

echo "input: <42.0fq>"
./parser 42.0fq

echo "input: <nan>"
./parser nan

echo "input: <inf>"
./parser inf

echo "input: <-inff>"
./parser -inff

echo "input: <test>"
./parser test

echo "input: <10.ewrewrf>"
./parser 10.ewrewrf

echo "input: <11111111>"
./parser 11111111

echo "input: <111111>"
./parser 111111

echo "input: <1111111111111>"
./parser 1111111111111

echo "input: <111111111111111111111111111111111111111111111111111111111>"
./parser 111111111111111111111111111111111111111111111111111111111
