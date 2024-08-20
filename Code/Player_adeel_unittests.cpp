#include "pch.h"

using namespace std;

//Each Aspect of the Code is taken into Account and i think this will give 100% Code Coverage
class PlayerAdeelUnitTest : public ::testing::Test
{
public:
    PlayerAdeelUnitTest(): ::testing::Test()
    {
        fill(begin(m_boardForTesting), end(m_boardForTesting), 0);
    }

    const string m_playerName{"Player_Adeel"};

    static bool wrapperForGetIfValuesAreEqual(const int first, const int second, const int third, const int fourth)
    {
        return Player_adeel::areValuesEqual(first, second, third, fourth);
    }

    static Result wrapperForGetResultsIfGameOver(int ticTacBoard[])
    {
        return Player_adeel::getResultIfGameOver(ticTacBoard);
    }

    static int wrapperForRunMiniMax(int ticTacBoard[], int depth, bool isMaximizing)
    {
        Player_adeel player{};
        return player.runMiniMax(ticTacBoard, depth, isMaximizing);
    }

    static int wrapperForGetNextMove(int ticTacBoard[])
    {
        Player_adeel player{};
        return player.getNextMove(ticTacBoard);
    }


    int m_boardForTesting[17];
    int m_depthTest = Player_adeel::m_cutOffDepth;
    bool m_isMaximizingTest = false;
};

// Test class constructor
TEST_F(PlayerAdeelUnitTest, constructor) {

  Player_adeel adeelPlayer{};
  EXPECT_TRUE(true);
}

TEST_F(PlayerAdeelUnitTest, playerName) {

    Player_adeel adeelPlayer{};
    const auto playerName = adeelPlayer.get_dev_name();
    EXPECT_EQ(playerName, m_playerName);
}

TEST_F(PlayerAdeelUnitTest, areValuesNotEqual) 
{

    const int first{ 0 };
    const int second{ 0 };
    const int third{ 0 };
    const int fourth{ 0 };

        EXPECT_FALSE(wrapperForGetIfValuesAreEqual(first, second, third, fourth));
}

TEST_F(PlayerAdeelUnitTest, areValuesEqual)
{
    const int first{1};
    const int second{1};
    const int third{1};
    const int fourth{1};

    EXPECT_TRUE(wrapperForGetIfValuesAreEqual(first, second, third, fourth));
}


TEST_F(PlayerAdeelUnitTest, getResultIfGameOverWhenPlayerOneWon)
{
    // case-01: player one won with forward diagonal.
    {
        m_boardForTesting[1] = 1;
        m_boardForTesting[6] = 1;
        m_boardForTesting[11] = 1;
        m_boardForTesting[16] = 1;

    EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer1);
    
    }

    // case-02: player one won with backward diagonal.
    {
        m_boardForTesting[4] = 1;
        m_boardForTesting[7] = 1;
        m_boardForTesting[10] = 1;
        m_boardForTesting[13] = 1;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer1);
    }

    // case-03: player one won with horizontal.
    {
        m_boardForTesting[1] = 1;
        m_boardForTesting[2] = 1;
        m_boardForTesting[3] = 1;
        m_boardForTesting[4] = 1;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer1);
    }

    // case-04: player one won with vertical.
    {
        m_boardForTesting[1] = 1;
        m_boardForTesting[5] = 1;
        m_boardForTesting[9] = 1;
        m_boardForTesting[13] = 1;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer1);
    }

}

TEST_F(PlayerAdeelUnitTest, getResultIfGameOverWhenPlayerTwoWon)
{
    // case-01: player two won with forward diagonal.
    {
        m_boardForTesting[1] = 2;
        m_boardForTesting[6] = 2;
        m_boardForTesting[11] = 2;
        m_boardForTesting[16] = 2;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer2);

    }

    // case-02: player two won with backward diagonal.
    {
        m_boardForTesting[4] =  2;
        m_boardForTesting[7] =  2;
        m_boardForTesting[10] = 2;
        m_boardForTesting[13] = 2;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer2);
    }

    // case-03: player two won with horizontal.
    {
        m_boardForTesting[1] = 2;
        m_boardForTesting[2] = 2;
        m_boardForTesting[3] = 2;
        m_boardForTesting[4] = 2;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer2);
    }

    // case-04: player two won with vertical.
    {
        m_boardForTesting[1] = 2;
        m_boardForTesting[5] = 2;
        m_boardForTesting[9] = 2;
        m_boardForTesting[13] = 2;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::WonPlayer2);
    }

}

TEST_F(PlayerAdeelUnitTest, getResultIfGameOverWhenBothPlayerTie)
{
    {
        // fill board with tie values.
        fill(begin(m_boardForTesting), end(m_boardForTesting), 3);
        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::Tie);
    }
}

TEST_F(PlayerAdeelUnitTest, getResultIfGameOverWhenGameNotOver)
{
    {
        m_boardForTesting[1] = 1;
        m_boardForTesting[5] = 1;
        m_boardForTesting[9] = 2;
        m_boardForTesting[13] = 2;

        EXPECT_EQ(wrapperForGetResultsIfGameOver(m_boardForTesting), Result::GameOnGoing);
    }
}

TEST_F(PlayerAdeelUnitTest, runMinimaxDepthCutOff)
{
    // By default m_depthTest is set to depth cut off. Thus it should return 0.
    EXPECT_EQ(wrapperForRunMiniMax(m_boardForTesting, m_depthTest, m_isMaximizingTest), 0);
}

TEST_F(PlayerAdeelUnitTest, runMinimaxGameOver)
{
    // By default m_depthTest is set to depth cut off. So set to 0.
    m_depthTest=0;
    // Set game board to player one won.
    m_boardForTesting[1] = 1;
    m_boardForTesting[5] = 1;
    m_boardForTesting[9] = 1;
    m_boardForTesting[13] = 1;
    // Expect score to be 10 as player 1 won.
    EXPECT_EQ(wrapperForRunMiniMax(m_boardForTesting, m_depthTest, m_isMaximizingTest), 10);
}

TEST_F(PlayerAdeelUnitTest, runMinimaxTestMaximizing)
{
    // By default m_depthTest is set to depth cut off. So set to 0.
    m_depthTest=0;
    // Set game board.
    m_boardForTesting[1] = 3;
    m_boardForTesting[2] = 1;
    m_boardForTesting[3] = 1;
    m_boardForTesting[4] = 2;
    m_boardForTesting[5] = 2;
    m_boardForTesting[6] = 1;
    m_boardForTesting[7] = 1;
    m_boardForTesting[8] = 2;
    m_boardForTesting[9] = 1;
    m_boardForTesting[10] = 2;

    m_isMaximizingTest = true;
    EXPECT_EQ(wrapperForRunMiniMax(m_boardForTesting, m_depthTest, m_isMaximizingTest), 0);
}

TEST_F(PlayerAdeelUnitTest, getNextMove)
{
    // Set game board.
    m_boardForTesting[6] = 1;
    m_boardForTesting[7] = 1;
    m_boardForTesting[8] = 2;
    m_boardForTesting[9] = 1;
    m_boardForTesting[10] = 2;
    m_boardForTesting[1] = 3;
    m_boardForTesting[2] = 1;
    m_boardForTesting[3] = 1;
    m_boardForTesting[4] = 2;
    m_boardForTesting[5] = 2;

    EXPECT_EQ(wrapperForGetNextMove(m_boardForTesting), 11);
}