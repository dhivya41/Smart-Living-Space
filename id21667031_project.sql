-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Aug 06, 2024 at 10:18 AM
-- Server version: 10.5.20-MariaDB
-- PHP Version: 7.3.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `id21667031_project`
--

-- --------------------------------------------------------

--
-- Table structure for table `door`
--

CREATE TABLE `door` (
  `status` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `door`
--

INSERT INTO `door` (`status`) VALUES
(1);

-- --------------------------------------------------------

--
-- Table structure for table `garden`
--

CREATE TABLE `garden` (
  `temp` int(5) NOT NULL,
  `hum` int(5) NOT NULL,
  `sm` int(5) NOT NULL,
  `pump` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `garden`
--

INSERT INTO `garden` (`temp`, `hum`, `sm`, `pump`) VALUES
(44, 55, 0, 1),
(44, 55, 0, 1);

-- --------------------------------------------------------

--
-- Table structure for table `home`
--

CREATE TABLE `home` (
  `temp` int(5) NOT NULL,
  `hum` int(5) NOT NULL,
  `ldr` int(5) NOT NULL,
  `gas` int(5) NOT NULL,
  `status` int(5) NOT NULL,
  `light` int(5) NOT NULL,
  `fan` int(5) NOT NULL,
  `eeg` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `home`
--

INSERT INTO `home` (`temp`, `hum`, `ldr`, `gas`, `status`, `light`, `fan`, `eeg`) VALUES
(22, 33, 44, 0, 0, 0, 1, 0);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
