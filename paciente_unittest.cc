#include "paciente.h"
#include "gtest/gtest.h"

TEST(Paciente, ConstructorParametrosDefecto) {
  Paciente p("33XX","44XX");
  
  
  EXPECT_EQ("33XX", p.getNombre());
  EXPECT_EQ("44XX", p.getApellidos());
  EXPECT_EQ("", p.getTelefono());
  EXPECT_EQ("", p.getPeso());
  EXPECT_EQ(0, p.getEdad());
  EXPECT_EQ(", ", p.getAltura());
}

