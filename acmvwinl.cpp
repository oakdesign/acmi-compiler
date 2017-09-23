#include "F4error.h"
#include "sim\include\misctemp.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ACMIView inlines.

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline ACMITape *ACMIView::Tape() 
{
	return _tape; 
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline RViewPoint *ACMIView::Viewpoint() 
{
	return _viewPoint; 
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline void ACMIView::IncrementCameraObject(int inc) 
{ 
	int numEnt = _tape->NumEntities();
	int i;

	if ( inc > 0 )
	{
		for ( i = _currentCam + 1; i < numEnt; i++ )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentCam = i;
				return;
			}
		}
		for ( i = 0; i < _currentCam; i++ )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentCam = i;
				return;
			}
		}
	}
	else
	{
		for ( i = _currentCam - 1; i >= 0; i-- )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentCam = i;
				return;
			}
		}
		for ( i = numEnt - 1; i > _currentCam; i-- )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentCam = i;
				return;
			}
		}
	}

}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline void ACMIView::SetCameraObject(int theObject) 
{
	F4Assert(theObject >= 0);
	F4Assert(theObject < _tape->NumEntities() );

	_currentCam = theObject; 
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline int ACMIView::CameraObject() 
{ 
	return _currentCam;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline void ACMIView::IncrementTrackingObject(int inc) 
{ 
	int numEnt = _tape->NumEntities();
	int i;

	if ( inc > 0 )
	{
		for ( i = _currentEntityCam + 1; i < numEnt; i++ )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentEntityCam = i;
				return;
			}
		}
		for ( i = 0; i < _currentEntityCam; i++ )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentEntityCam = i;
				return;
			}
		}
	}
	else
	{
		for ( i = _currentEntityCam - 1; i >= 0; i-- )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentEntityCam = i;
				return;
			}
		}
		for ( i = numEnt - 1; i > _currentEntityCam; i-- )
		{
			if ( _entityUIMappings[ i ].listboxId != -1 )
			{
				_currentEntityCam = i;
				return;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline void ACMIView::SetTrackingObject(int theObject) 
{
	F4Assert(theObject >= 0);
	F4Assert(theObject < _tape->NumEntities() );

	_currentEntityCam = theObject;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

inline int ACMIView::TrackingObject()
{
	return _currentEntityCam;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

