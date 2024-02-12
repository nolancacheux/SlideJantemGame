-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : jeu. 09 juin 2022 à 09:10
-- Version du serveur :  5.7.24
-- Version de PHP : 8.0.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `d6xINafhrw`
--

-- --------------------------------------------------------

--
-- Structure de la table `game`
--

CREATE TABLE `game` (
  `ID` int(2) NOT NULL,
  `username` varchar(64) NOT NULL,
  `player` int(1) NOT NULL DEFAULT '1',
  `trail` int(1) NOT NULL DEFAULT '1',
  `score` int(3) NOT NULL DEFAULT '0',
  `map1` int(2) NOT NULL DEFAULT '0',
  `map2` int(2) NOT NULL DEFAULT '0',
  `map3` int(2) NOT NULL DEFAULT '0',
  `map4` int(2) NOT NULL DEFAULT '0',
  `map5` int(2) NOT NULL DEFAULT '0',
  `map6` int(2) NOT NULL DEFAULT '0',
  `map7` int(2) NOT NULL DEFAULT '0',
  `map8` int(2) NOT NULL DEFAULT '0',
  `map9` int(2) NOT NULL DEFAULT '0',
  `map10` int(2) NOT NULL DEFAULT '0',
  `map11` int(2) NOT NULL DEFAULT '0',
  `map12` int(2) NOT NULL DEFAULT '0',
  `map13` int(2) NOT NULL DEFAULT '0',
  `map14` int(2) NOT NULL DEFAULT '0',
  `map15` int(2) NOT NULL DEFAULT '0',
  `map16` int(2) NOT NULL DEFAULT '0',
  `map17` int(2) NOT NULL DEFAULT '0',
  `map18` int(2) NOT NULL DEFAULT '0',
  `map19` int(2) NOT NULL DEFAULT '0',
  `map20` int(2) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `game`
--

INSERT INTO `game` (`ID`, `username`, `player`, `trail`, `score`, `map1`, `map2`, `map3`, `map4`, `map5`, `map6`, `map7`, `map8`, `map9`, `map10`, `map11`, `map12`, `map13`, `map14`, `map15`, `map16`, `map17`, `map18`, `map19`, `map20`) VALUES
(14, 'Nolan', 1, 1, 984, 336, 352, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17, 'oui', 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(18, 'sacha', 1, 1, 380, 380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(19, 'Proxinou', 1, 1, 1448, 324, 368, 264, 184, 308, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(20, 'Ramzy', 1, 1, 3004, 380, 368, 316, 348, 292, 288, 368, 228, 112, 304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(22, 'mylow', 1, 1, 5952, 380, 368, 336, 348, 268, 304, 364, 272, 232, 308, 228, 308, 328, 284, 204, 244, 288, 296, 320, 272),
(23, 'david', 1, 1, 5356, 380, 368, 336, 352, 284, 324, 364, 268, 0, 0, 256, 300, 272, 268, 196, 244, 260, 284, 320, 280);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `game`
--
ALTER TABLE `game`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `game`
--
ALTER TABLE `game`
  MODIFY `ID` int(2) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
