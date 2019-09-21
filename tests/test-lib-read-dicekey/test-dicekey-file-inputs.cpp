#include "gtest/gtest.h"
#include "../../lib-read-dicekey/read-dice.h";
#include "../../lib-read-dicekey/validate-dice.h";
#include <filesystem>

std::string basePath;

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  //assert(argc == 2); // gtest leaved unparsed arguments for you
  if (argc == 2) {
    basePath = argv[1];
  }
  return RUN_ALL_TESTS();
}

void testFile(std::string filePath = ::testing::UnitTest::GetInstance()->current_test_info()->name() ) {
  std::cerr << "Using base path" << basePath;
  cv::Mat image = cv::imread(basePath + "/" + filePath, cv::IMREAD_COLOR);
  ASSERT_FALSE(image.empty()) << "No such file at " << filePath;
  
  const size_t indexOfLastSlash = filePath.find_last_of("/") + 1;
  const std::string filename = filePath.substr(indexOfLastSlash);

  try {
    const auto diceRead = readDice(image, true);
    //const cv::Mat dieReadOutput = visualizeReadResults(image, diceRead, true);
    //cv::imwrite("out/" + filename.substr(0, filename.length() - 4) + "-results.png", dieReadOutput);
    const DiceKey diceKeyNonCanonical = diceReadToDiceKey(diceRead.dice, true);
  	const DiceKey diceKey = diceKeyNonCanonical.rotateToCanonicalOrientation();
    
    validateDiceRead(diceRead.dice, filename.substr(0, 75));
    std::cerr << "Validated " << filename << "\n";
  } catch (std::string errStr) {
    std::cerr << "Exception in " << filename << "\n  " << errStr << "\n";
    ASSERT_TRUE(false);
  }
}

TEST(DiceKeyTestInputs, A32W41T31I33Z52J21X20F21L63V52M43B33U22O43K30R21S62Y22P63E20G61H32N22C33D11 ) {
  testFile("./img/A32W41T31I33Z52J21X20F21L63V52M43B33U22O43K30R21S62Y22P63E20G61H32N22C33D11.jpg");
}
// TEST(DiceKeyTestInputs, ) { testFile("A53X23Y63Z60R32E53F31P33N42D21I62L21H11O11B10T40K63W40C50M12G12S50U61V51J40.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("B21U11Z30O62W51C10D22T22F61X52I11R30L21H52A22K11P40J33V51Y41M33S20N63E60G32.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("B23X21K21Y63F53I50O11H12J40M13G10P40C60S33U23A21W62L60V42D33T32Z61N13E33R63.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("C22I12L11G51P31F53K22V40S13W53T31O50Z30B13M51E22J13H43U30A13D62N13R61X60Y41-faded.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("C22I12L11G51P31F53K22V40S13W53T31O50Z30B13M51E22J13H43U30A13D62N13R61X60Y41-super-low-res.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("E12U31P11C51K13B31O53A60R51I21M12Y21T61Z60N10L61G40W21X12J30V31D22F33H21S32.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("G21J20C42Y50L10Z12E40T23M62B20O10S12I11D22A30P32H31V33F52R43X21U62K41W40N32.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("H10A22Y23I43L42M60J20E61W32D43Z21V33T33G33K40X32B43N10R63O60U40S61F13C40P41.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("H21Z40F20D13M20P20T50X33V11W51A43C51U31I12O63N42R33B12S51L42Y61G33J30E53K42-angle.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("K13Y63A23S13X61C50P43M10B50R33L41V40D50G61U50I42E41T13H50F32O40N11W60J11Z31-glare.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("K13Y63A23S13X61C50P43M10B50R33L41V40D50G61U50I42E41T13H50F32O40N11W60J11Z31.jpg"); }
// TEST(DiceKeyTestInputs, ) { testFile("R60D50Y32B60Z40O63L30K51J21M50G60P33X61E20A43U63S51F10C21H41V23N51T10I32W12.jpg"); }

