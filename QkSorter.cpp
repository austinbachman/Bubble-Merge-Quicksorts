// Program Information ////////////////////////////////////////////////////////
/**
 * @file QkSorter.cpp
 *
 * @brief Implementation file for QkSorter class
 * 
 * @details Implements all member methods of the QkSorter class
 *
 * @version 1.00 
 *          Austin Bachman (20 February 2016)
 *          Original code
 *
 * @Note Requires QkSorter.h
 */

#include "QkSorter.h"

/**
 * @brief Default/Initialization QkSorter constructor
 *
 * @details Constructs QkSorter with default capacity
 *          
 * @pre assumes Uninitialized QkSorter object
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
QkSorter::QkSorter
   (
   	// no parameters
   )
{
	// parent default constructor called
}

/**
 * @brief Initialization QkSorter constructor
 *
 * @details Constructs QkSorter with given capacity
 *          
 * @pre assumes Uninitialized QkSorter object
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
QkSorter::QkSorter
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
 * @pre Assumes uninitialized QkSorter object
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
QkSorter::QkSorter
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
 * @details Removes or verifies removal of all data in QkSorter
 *          
 * @pre Assumes QkSorter capacity >= 0
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
QkSorter::~QkSorter
   (
    // no parameters
   )
{
  // parent destructor called
}

/**
 * @brief Sort function
 *
 * @details Quick sorts data
 *          
 * @pre Assumes QkSorter initialized with data
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
void QkSorter::sort
   (
    //no parameters
   )
{
    sortHelper( 0, ( this->getSize() - 1 ) );
}

/**
 * @brief Quick sorts data in QkSorter
 *
 * @details Uses quick sorting algorithm to order data
 *          
 * @pre Assumes data found in elements
 *
 * @post All data has been sorted in ascending order
 *
 * @par Algorithm 
 *      Calls partition method to find pivot and sort, then calls
 *      itself recursively on both halves
 * 
 * @exception None
 *
 * @param [in] leftLimitIndex
 *             Index to begin sorting from
 *             
 * @param [in] rightLimitIndex
 *             Index to end sorting at
 *             
 * @return None
 *
 * @note None
 */
void QkSorter::sortHelper
   (
    int leftLimitIndex,     // input: index to begin sort group
    int rightLimitIndex     // input: index to end sort group
   )
{
    int left = leftLimitIndex;
    int right = rightLimitIndex;
    int pivotIndex;

    if( left < right )
    {
        pivotIndex = partition( left, right );
        sortHelper( left, ( pivotIndex - 1 ) );
        sortHelper( ( pivotIndex + 1 ), right );
    }

}

/**
 * @brief Partitions data in QkSorter
 *
 * @details Used by quick sorting algorithm to order data
 *          
 * @pre Assumes data found in elements
 *
 * @post Data partitioned around pivot
 *
 * @par Algorithm 
 *      Finds pivot and sorts data around it, returns
 *      the partition index to calling function
 * 
 * @exception None
 *
 * @param [in] leftLimitIndex
 *             Index to begin sorting from
 *             
 * @param [in] rightLimitIndex
 *             Index to end sorting at
 *             
 * @return Int with partition index
 *
 * @note None
 */
int QkSorter::partition
   (
    int leftLimitIndex,     // input: index to begin partitiion
    int rightLimitIndex     // input: index to end partition
   )
{
    int first = leftLimitIndex;
    int last = rightLimitIndex;
    int mid = first + ( (last - first) / 2 );

    StudentType pivot = this->getAtIndex( mid );
    StudentType tempItem1, tempItem2;

    this->swapBetween( mid, first);

    while( first <= last )
    {
        tempItem1 = getAtIndex( first );
        tempItem2 = getAtIndex( last );

        while( ( first <= last ) && ( tempItem1.compareTo( pivot ) <= 0 ) )
        {
            first++;
            tempItem1 = getAtIndex( first );
        }

        while( ( first <= last ) && ( tempItem2.compareTo( pivot ) > 0 ) )
        {
            last--;
            tempItem2 = getAtIndex( last );
        }

        if( first < last )
        {
            this->swapBetween( first, last );
        }
    }

    this->swapBetween( ( first - 1 ), leftLimitIndex );

    return ( first - 1 );
}