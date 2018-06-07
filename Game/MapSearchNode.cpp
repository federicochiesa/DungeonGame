#include "MapSearchNode.hpp"

bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{
    if( (x == rhs.x) && (y == rhs.y) ) return true;
    else return false;
}

void MapSearchNode::PrintNodeInfo()
{
    cout << "Node position:(" << x << "," << y << ")" << std::endl;
}

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
    return std::abs(x - nodeGoal.x) + std::abs(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{
    if( (x == nodeGoal.x) && (y == nodeGoal.y) ) return true;
    return false;
}

bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{
    
    int parent_x = -1;
    int parent_y = -1;
    
    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }
    MapSearchNode NewNode;
    if( (map::getMap( x-1, y ) < 9)
       && !((parent_x == x-1) && (parent_y == y))
       )
    {
        NewNode = MapSearchNode( x-1, y );
        astarsearch->AddSuccessor( NewNode );
    }
    
    if( (map::getMap( x, y-1 ) < 9)
       && !((parent_x == x) && (parent_y == y-1))
       )
    {
        NewNode = MapSearchNode( x, y-1 );
        astarsearch->AddSuccessor( NewNode );
    }
    
    if( (map::getMap( x+1, y ) < 9)
       && !((parent_x == x+1) && (parent_y == y))
       )
    {
        NewNode = MapSearchNode( x+1, y );
        astarsearch->AddSuccessor( NewNode );
    }
    
    
    if( (map::getMap( x, y+1 ) < 9)
       && !((parent_x == x) && (parent_y == y+1))
       )
    {
        NewNode = MapSearchNode( x, y+1 );
        astarsearch->AddSuccessor( NewNode );
    }
    return true;
}

float MapSearchNode::GetCost( MapSearchNode &successor )
{
    return (float) map::getMap( x, y );
}

int MapSearchNode::computePath()
{
    AStarSearch<MapSearchNode> astarsearch;
    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;
    while(SearchCount < NumSearches)
    {
        MapSearchNode nodeStart;
        nodeStart.x = 7;
        nodeStart.y = 9;
        MapSearchNode nodeEnd;
        nodeEnd.x = 13;
        nodeEnd.y = 18;
        
        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );
        unsigned int SearchState;
        unsigned int SearchSteps = 0;
        do
        {
            SearchState = astarsearch.SearchStep();
            SearchSteps++;
        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );
        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
        {
            cout << "Search found goal state\n";
            MapSearchNode *node = astarsearch.GetSolutionStart();
            int steps = 0;
            node->PrintNodeInfo();
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();
                if( !node ) break;
                node->PrintNodeInfo();
                steps ++;
            };
            cout << "Solution steps: " << steps << endl;
            astarsearch.FreeSolutionNodes();
        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ) cout << "Search terminated. Did not find goal state\n";
        cout << "SearchSteps : " << SearchSteps << "\n";
        SearchCount ++;
        astarsearch.EnsureMemoryFreed();
    }
    return 0;
}

