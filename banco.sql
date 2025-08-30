create database academia;
use academia;
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema tabelas
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema tabelas
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `tabelas` DEFAULT CHARACTER SET utf8 ;
-- -----------------------------------------------------
-- Schema new_schema1
-- -----------------------------------------------------
USE `tabelas` ;

-- -----------------------------------------------------
-- Table `tabelas`.`matricula`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`matricula` (
  `id_matricula` INT NOT NULL,
  `id_aluno` INT NOT NULL,
  `data_inicio` DATE NOT NULL,
  `status` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_matricula`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tabelas`.`aluno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`aluno` (
  `id_aluno` INT NOT NULL,
  `nome` VARCHAR(150) NOT NULL,
  `data_Nascimento` DATE NOT NULL,
  `telefone` VARCHAR(20) NOT NULL,
  `e-mail` VARCHAR(45) NOT NULL,
  `matricula_id_matricula` INT NOT NULL,
  PRIMARY KEY (`id_aluno`, `matricula_id_matricula`),
  INDEX `fk_aluno_matricula1_idx` (`matricula_id_matricula` ASC) VISIBLE,
  CONSTRAINT `fk_aluno_matricula1`
    FOREIGN KEY (`matricula_id_matricula`)
    REFERENCES `tabelas`.`matricula` (`id_matricula`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tabelas`.`instrutor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`instrutor` (
  `id_instrutor` INT NOT NULL,
  `nome` VARCHAR(150) NOT NULL,
  `especialidade` VARCHAR(45) NOT NULL,
  `telefone` VARCHAR(20) NOT NULL,
  `aluno_id_aluno` INT NOT NULL,
  PRIMARY KEY (`id_instrutor`, `aluno_id_aluno`),
  INDEX `fk_instrutor_aluno1_idx` (`aluno_id_aluno` ASC) VISIBLE,
  CONSTRAINT `fk_instrutor_aluno1`
    FOREIGN KEY (`aluno_id_aluno`)
    REFERENCES `tabelas`.`aluno` (`id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tabelas`.`pagamento`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`pagamento` (
  `id_pagamento` INT NOT NULL,
  `id_aluno` INT NOT NULL,
  `data_pagamento` DATE NOT NULL,
  `valor` FLOAT NOT NULL,
  `status` VARCHAR(45) NULL,
  `matricula_id_matricula` INT NOT NULL,
  `aluno_id_aluno` INT NOT NULL,
  `aluno_matricula_id_matricula` INT NOT NULL,
  PRIMARY KEY (`id_pagamento`, `matricula_id_matricula`, `aluno_id_aluno`, `aluno_matricula_id_matricula`),
  INDEX `fk_pagamento_matricula1_idx` (`matricula_id_matricula` ASC) VISIBLE,
  INDEX `fk_pagamento_aluno1_idx` (`aluno_id_aluno` ASC, `aluno_matricula_id_matricula` ASC) VISIBLE,
  CONSTRAINT `fk_pagamento_matricula1`
    FOREIGN KEY (`matricula_id_matricula`)
    REFERENCES `tabelas`.`matricula` (`id_matricula`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_pagamento_aluno1`
    FOREIGN KEY (`aluno_id_aluno` , `aluno_matricula_id_matricula`)
    REFERENCES `tabelas`.`aluno` (`id_aluno` , `matricula_id_matricula`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tabelas`.`exercicio`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`exercicio` (
  `id_exercicio` INT NOT NULL,
  `nome` VARCHAR(150) NOT NULL,
  `grupo_muscular` VARCHAR(150) NOT NULL,
  `descrição` VARCHAR(200) NOT NULL,
  `aluno_id_aluno` INT NOT NULL,
  PRIMARY KEY (`id_exercicio`, `aluno_id_aluno`),
  INDEX `fk_exercicio_aluno1_idx` (`aluno_id_aluno` ASC) VISIBLE,
  CONSTRAINT `fk_exercicio_aluno1`
    FOREIGN KEY (`aluno_id_aluno`)
    REFERENCES `tabelas`.`aluno` (`id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tabelas`.`plano exercicio`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`plano exercicio` (
  `id_plano_exercicio` INT NOT NULL,
  `id_exercicio` INT NOT NULL,
  `series` INT NOT NULL,
  `repeticoes` INT NOT NULL,
  `exercicio_id_exercicio` INT NOT NULL,
  `exercicio_aluno_id_aluno` INT NOT NULL,
  PRIMARY KEY (`id_plano_exercicio`, `exercicio_id_exercicio`, `exercicio_aluno_id_aluno`),
  INDEX `fk_plano exercicio_exercicio1_idx` (`exercicio_id_exercicio` ASC, `exercicio_aluno_id_aluno` ASC) VISIBLE,
  CONSTRAINT `fk_plano exercicio_exercicio1`
    FOREIGN KEY (`exercicio_id_exercicio` , `exercicio_aluno_id_aluno`)
    REFERENCES `tabelas`.`exercicio` (`id_exercicio` , `aluno_id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tabelas`.`plano de treino`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`plano de treino` (
  `id_plano` INT NOT NULL,
  `nome` VARCHAR(255) NOT NULL,
  `descrição` VARCHAR(45) NOT NULL,
  `duração_semanais` INT NOT NULL,
  `id_instrutor` VARCHAR(45) NULL,
  `aluno_id_aluno` INT NOT NULL,
  `instrutor_id_instrutor` INT NOT NULL,
  `instrutor_aluno_id_aluno` INT NOT NULL,
  `plano exercicio_id_plano_exercicio` INT NOT NULL,
  `plano exercicio_exercicio_id_exercicio` INT NOT NULL,
  `plano exercicio_exercicio_aluno_id_aluno` INT NOT NULL,
  PRIMARY KEY (`id_plano`, `aluno_id_aluno`, `instrutor_id_instrutor`, `instrutor_aluno_id_aluno`, `plano exercicio_id_plano_exercicio`, `plano exercicio_exercicio_id_exercicio`, `plano exercicio_exercicio_aluno_id_aluno`),
  INDEX `fk_plano de treino_aluno1_idx` (`aluno_id_aluno` ASC) VISIBLE,
  INDEX `fk_plano de treino_instrutor1_idx` (`instrutor_id_instrutor` ASC, `instrutor_aluno_id_aluno` ASC) VISIBLE,
  INDEX `fk_plano de treino_plano exercicio1_idx` (`plano exercicio_id_plano_exercicio` ASC, `plano exercicio_exercicio_id_exercicio` ASC, `plano exercicio_exercicio_aluno_id_aluno` ASC) VISIBLE,
  CONSTRAINT `fk_plano de treino_aluno1`
    FOREIGN KEY (`aluno_id_aluno`)
    REFERENCES `tabelas`.`aluno` (`id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_plano de treino_instrutor1`
    FOREIGN KEY (`instrutor_id_instrutor` , `instrutor_aluno_id_aluno`)
    REFERENCES `tabelas`.`instrutor` (`id_instrutor` , `aluno_id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_plano de treino_plano exercicio1`
    FOREIGN KEY (`plano exercicio_id_plano_exercicio` , `plano exercicio_exercicio_id_exercicio` , `plano exercicio_exercicio_aluno_id_aluno`)
    REFERENCES `tabelas`.`plano exercicio` (`id_plano_exercicio` , `exercicio_id_exercicio` , `exercicio_aluno_id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tabelas`.`exercicio_has_plano de treino`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tabelas`.`exercicio_has_plano de treino` (
  `exercicio_id_exercicio` INT NOT NULL,
  `exercicio_aluno_id_aluno` INT NOT NULL,
  `plano de treino_id_plano` INT NOT NULL,
  `plano de treino_aluno_id_aluno` INT NOT NULL,
  `plano de treino_instrutor_id_instrutor` INT NOT NULL,
  `plano de treino_instrutor_aluno_id_aluno` INT NOT NULL,
  `plano de treino_plano exercicio_id_plano_exercicio` INT NOT NULL,
  `plano de treino_plano exercicio_exercicio_id_exercicio` INT NOT NULL,
  `plano de treino_plano exercicio_exercicio_aluno_id_aluno` INT NOT NULL,
  PRIMARY KEY (`exercicio_id_exercicio`, `exercicio_aluno_id_aluno`, `plano de treino_id_plano`, `plano de treino_aluno_id_aluno`, `plano de treino_instrutor_id_instrutor`, `plano de treino_instrutor_aluno_id_aluno`, `plano de treino_plano exercicio_id_plano_exercicio`, `plano de treino_plano exercicio_exercicio_id_exercicio`, `plano de treino_plano exercicio_exercicio_aluno_id_aluno`),
  INDEX `fk_exercicio_has_plano de treino_plano de treino1_idx` (`plano de treino_id_plano` ASC, `plano de treino_aluno_id_aluno` ASC, `plano de treino_instrutor_id_instrutor` ASC, `plano de treino_instrutor_aluno_id_aluno` ASC, `plano de treino_plano exercicio_id_plano_exercicio` ASC, `plano de treino_plano exercicio_exercicio_id_exercicio` ASC, `plano de treino_plano exercicio_exercicio_aluno_id_aluno` ASC) VISIBLE,
  INDEX `fk_exercicio_has_plano de treino_exercicio1_idx` (`exercicio_id_exercicio` ASC, `exercicio_aluno_id_aluno` ASC) VISIBLE,
  CONSTRAINT `fk_exercicio_has_plano de treino_exercicio1`
    FOREIGN KEY (`exercicio_id_exercicio` , `exercicio_aluno_id_aluno`)
    REFERENCES `tabelas`.`exercicio` (`id_exercicio` , `aluno_id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_exercicio_has_plano de treino_plano de treino1`
    FOREIGN KEY (`plano de treino_id_plano` , `plano de treino_aluno_id_aluno` , `plano de treino_instrutor_id_instrutor` , `plano de treino_instrutor_aluno_id_aluno` , `plano de treino_plano exercicio_id_plano_exercicio` , `plano de treino_plano exercicio_exercicio_id_exercicio` , `plano de treino_plano exercicio_exercicio_aluno_id_aluno`)
    REFERENCES `tabelas`.`plano de treino` (`id_plano` , `aluno_id_aluno` , `instrutor_id_instrutor` , `instrutor_aluno_id_aluno` , `plano exercicio_id_plano_exercicio` , `plano exercicio_exercicio_id_exercicio` , `plano exercicio_exercicio_aluno_id_aluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
