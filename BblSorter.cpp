// Program Information ////////////////////////////////////////////////////////
/**
 * @file BblSorter.cpp
 *
 * @brief Implementation file for BblSorter class
 * 
 * @details Implements all member methods of the BblSorter class
 *
 * @version 1.00 
 *          Austin Bachman (20 February 2016)
 *          Original code
 *
 * @Note Requires BblSorter.h
 */

#include "BblSorter.h"

/**
 * @brief Default/Initialization BblSorter constructor
 *
 * @details Constructs BblSorter with default capacity
 *          
 * @pre assumes Uninitialized BblSorter object
 *
 * @post List of nodes is created for use as array
 *
 * @par Algorithm 
 *      Initializes class by calling parent constructor
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
BblSorter::BblSorter
   (
   	// no parameters
   )
{
	// parent default constructor called
}

/**
 * @brief Initialization BblSorter constructor
 *
 * @details Constructs BblSorter with given capacity
 *          
 * @pre assumes Uninitialized BblSorter object
 *
 * @post List of nodes is created for use as array
 *
 * @par Algorithm 
 *      Initializes class by calling parent constructor
 * 
 * @exception None
 *
 * @param [in] newCapacity
 *             Desired default or user-provided capacity
 *
 * @return None
 *
 * @note None
 */
BblSorter::BblSorter
   (
   	int initialCapacity     // input: capacity to initialize to
   )
       : SorterClass<StudentType>( initialCapacity )
{
	// parent constructor called
}

/**
 * @brief Copy constructor
 *
 * @details Creates local copy of all contents of parameter object
 *          
 * @pre Assumes uninitialized BblSorter object
 *
 * @par Algorithm 
 *      Calls parent constructor for copy process
 * 
 * @exception None
 *
 * @param [in] copiedVector
 *             Incoming Vector object
 *
 * @return None
 *
 * @note None
 */
BblSorter::BblSorter
   (
   	const SorterClass<StudentType> &copiedSorter     // input: vector to copy
   )
       : SorterClass<StudentType>( copiedSorter )
{
	// parent copy constructor called
}

/**
 * @brief Object destructor
 *
 * @details Removes or verifies removal of all data in BblSorter
 *          
 * @pre Assumes BblSorter capacity >= 0
 *
 * @par Algorithm
 *      Calls parent destructor
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
BblSorter::~BblSorter
   (
   	// no parameters
   )
{
	// parent destructor called
}

/**
 * @brief Sort function
 *
 * @details Bubble sorts data
 *          
 * @pre Assumes BblSorter initialized with data
 *
 * @par Algorithm
 *      Calls sortHelper method
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
void BblSorter::sort
   (
   	//no parameters
   )
{
	sortHelper( this->getSize() - 1 );
}

/**
 * @brief Quick sorts data in BblSorter
 *
 * @details Uses bubble sorting algorithm to order data
 *          
 * @pre Assumes data found in elements
 *
 * @post All data has been sorted in ascending order
 *
 * @par Algorithm 
 *      Loops through list, swapping items that aren't
 *      ordered correctly until no swaps are made
 * 
 * @exception None
 *
 * @param [in] index
 *             Index to end sort at
 *             
 * @return Bool value of swapped
 *
 * @note None
 */
bool BblSorter::sortHelper
   (
   	int index     // input: index position to recursively sort to
   )
{
	int position = 0;

	StudentType item1, item2;
	
	bool swapped = true;

	while( swapped && (position < index) )
	{
		swapped = false;

		for( position = 0; position < index; position++ )
		{
			item1 = this->getAtIndex( position );
			item2 = this->getAtIndex( position + 1 );

			if( item1.compareTo( item2 ) > 0 )
			{
				swapBetween( position, position + 1 );
				swapped = true;
			}			
		}

		sortHelper(index-1);
	}

	return swapped;
}